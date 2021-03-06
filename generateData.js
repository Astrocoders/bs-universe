const fs = require('fs')

console.log("Generating universe.json, please wait...")

const universe = fs.readdirSync('./packages').map(dir => {
  if(fs.existsSync(`packages/${dir}/package.json`)) {
    const { name: title, description } = JSON.parse(fs.readFileSync(`packages/${dir}/package.json`))
    return { title, description, url: `https://github.com/Astrocoders/bs-universe/tree/master/packages/${dir}` }
  }
  return null
}).filter(Boolean)

fs.writeFileSync('universe.json', JSON.stringify(universe, null, 2), 'utf-8')
