const fs = require('fs')

console.log("Generating universe.json, please wait...")

const files = fs.readdirSync('..')
const universe = []

for (let file of files) {
  if (fs.existsSync(`../${file}/package.json`)) {
    const data = JSON.parse(fs.readFileSync(`../${file}/package.json`))
    universe.push({
      title: data.name,
      description: data.description,
      url: `https://github.com/Astrocoders/bs-universe/tree/master/${file}`
    })
  }
}

fs.writeFileSync('universe.json', JSON.stringify(universe, null, 2), 'utf-8')
