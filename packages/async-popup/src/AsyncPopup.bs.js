// Generated by BUCKLESCRIPT VERSION 5.0.6, PLEASE EDIT WITH CARE
'use strict';


var start = (
    function(waitMessage) {
      let win = window.open('')
        win.document.write(`<h1>${waitMessage}</h1>`)
          return win
    }
  );

var setLocation = (
    function(win, url) {
      win.location = url
        win.focus()
        return win
    }
  );

exports.start = start;
exports.setLocation = setLocation;
/* start Not a pure module */