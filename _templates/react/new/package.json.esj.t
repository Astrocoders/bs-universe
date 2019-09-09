---
to: packages/<%= name %>/package.json
---

{
  "name": "<%= name %>",
  "version": "0.1.0",
  "scripts": {
    "build": "bsb -make-world",
    "start": "bsb -make-world -w -ws _ ",
    "clean": "bsb -clean-world",
    "test": "echo \"Error: no test specified\" && exit 1"
  },
  "keywords": [
    "BuckleScript"
  ],
  "author": "Astrocoders <contact@astrocoders.com>",
  "license": "MIT",
  "devDependencies": {
    "bs-platform": "^5.0.6",
    "react": "^16.2.0",
    "react-dom": "^16.2.0",
    "reason-react": ">=0.4.0"
  },
  "peerDependencies": {
    "react": "^16.2.0",
    "react-dom": "^16.2.0",
    "reason-react": ">=0.4.0"
  }
}