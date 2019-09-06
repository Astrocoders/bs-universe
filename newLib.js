const util = require('util')
const cp = require('child_process')

const projectName = process.argv.slice(2).toString()

const execAsync = util.promisify(cp.exec)

const isReact = process.env.IS_REACT ? 'react' : 'lib'

async function execute(command) {
  const logs = await execAsync(command)
  process.stdout.write(logs.stdout)
}

const main = async () => {
  await execute(`npx hygen ${isReact} new ${projectName}`)
  await execute(`npx lerna create ${projectName}  --yes`)
}

main()
