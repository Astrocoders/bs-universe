const util = require('util')
const cp = require('child_process')

const projectName = process.argv.slice(2).toString()

const execAsync = util.promisify(cp.exec)

async function execute(command) {
  const logs = await execAsync(command)
  process.stdout.write(logs.stdout)
}

const main = async () => {
  await execute(`npx hygen bs new ${projectName}`)
  await execute(`npx lerna create ${projectName}  --yes`)
}

main()

return 0

/*
async function execute(command) {
  exec(command, (err, stdout, stderr) => {
    if (err) throw err
    process.stdout.write(stdout)
  });
}
*/
