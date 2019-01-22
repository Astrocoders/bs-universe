type t;
type number('a) =
  | Float: number(float)
  | Int: number(int);

[@bs.module] [@bs.new]
external bignumber: ([@bs.ignore] number('a), 'a) => t = "bignumber.js";
[@bs.send] external plus: (t, [@bs.ignore] number('a), 'a) => t = "plus";
[@bs.send] external minus: (t, [@bs.ignore] number('a), 'a) => t = "minus";
[@bs.send] external dividedBy: (t, [@bs.ignore] number('a), 'a) => t = "dividedBy";
[@bs.send] external times: (t, [@bs.ignore] number('a), 'a) => t = "times";
[@bs.send] external toNumber: (t, [@bs.ignore] number('a)) => 'a = "toNumber";
[@bs.send]
external isEqualTo: (t, [@bs.ignore] number('a), 'a) => t = "isEqualTo";

let (+.) = (big, n) => big->plus(Float, n);
let (+) = (big, n) => big->plus(Int, n);

let (-.) = (big, n) => big->plus(Float, n);
let (-) = (big, n) => big->plus(Int, n);

let (/.) = (big, n) => big->dividedBy(Float, n);
let (/) = (big, n) => big->dividedBy(Int, n);

let (*.) = (big, n) => big->times(Float, n);
let (*) = (big, n) => big->times(Int, n);

let (==.) = (big, n) => big->isEqualTo(Float, n);
let (==) = (big, n) => big->isEqualTo(Int, n);

let toFloat = (big) => big->toNumber(Float);
let toInt = (big) => big->toNumber(Int);
