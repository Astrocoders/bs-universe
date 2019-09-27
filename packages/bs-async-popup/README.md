# Async Popup 

A simple module to open pop ups in ReasonML

## Installation

`yarn add bs-async-popup`

Then, add it to your `bsconfig.json`
```
"bs-dependencies": [
  "bs-async-popup"
]
```

## Usage
```ocaml
  let window = AsyncPopup.start("waiting message"); // Create the popup with a waiting message

  // Do some async stuff...

  AsyncPopup.setLocation(window, someUrl); // When the async stuff is done, set the new url for the window
```

