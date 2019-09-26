type window;

let start: string => window = [%bs.raw
  {|
    function(waitMessage) {
      let win = window.open('')
        win.document.write(`<h1>${waitMessage}</h1>`)
          return win
    }
  |}
];

let setLocation: (window, string) => window = [%bs.raw
  {|
    function(win, url) {
      win.location = url
        win.focus()
        return win
    }
  |}
];
