---
to: packages/<%= name %>/package.json
---

{
  "name": "<%= name %>",
  "version": "0.1.0",
  "scripts": {
    "build": "bsb -make-world",
    "start": "bsb -make-world -w",
    "clean": "bsb -clean-world"
  },
  "keywords": [
    "BuckleScript"
  ],
  "author": "Astrocoders <contact@astrocoders.com",
  "license": "MIT",
  "devDependencies": {
    "bs-platform": "^5.0.6"
  }
}