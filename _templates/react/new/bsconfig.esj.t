---
to: packages/<%= name %>/bsconfig.json
---

{
  "name": "<%= name %>",
  "reason": {
    "react-jsx": 2
  },
  "sources": {
    "dir" : "src",
    "subdirs" : true
  },
  "package-specs": [{
    "module": "commonjs",
    "in-source": true
  }],
  "suffix": ".bs.js",
  "namespace": true,
  "bs-dependencies": [
    "reason-react"
  ]
}
