const fs = require('fs')

console.log("Generating universe.json, please wait...")

const universe = fs.readdirSync('.').map(file => {
  if(fs.existsSync(`${file}/package.json`)) {
    const { name: title, description } = JSON.parse(fs.readFileSync(`${file}/package.json`))
    return { title, description, url: `https://github.com/Astrocoders/bs-universe/tree/master/${file}` }
  }
  return null
}).filter(Boolean)

fs.writeFileSync('universe.json', JSON.stringify(universe, null, 2), 'utf-8')
