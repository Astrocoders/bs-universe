[@bs.module "react-native-snap-carousel"] [@react.component]
external make:
  (
    ~layout: [@bs.string] [ | `default | `stack | `tinder]=?,
    ~data: array('a),
    ~renderItem: {
                   .
                   "item": 'a,
                   "index": int,
                 } =>
                 React.element,
    ~itemWidth: int,
    ~sliderWidth: int,
    ~itemHeight: int=?,
    ~sliderHeight: int=?,
    ~hasParallaxImages: bool=?,
    ~vertical: bool=?,
    ~layoutCardOffset: int=?,
    ~style: ReactNative.Style.t=?,
    ~slideStyle: ReactNative.Style.t=?,
    ~containerCustomStyle: ReactNative.Style.t=?,
    ~contentContainerCustomStyle: ReactNative.Style.t=?,
    ~onLayout: ReactNative.Event.layoutEvent => unit=?,
    ~onScroll: ReactNative.Event.layoutEvent => unit=?,
    ~onBeforeSnapToItem: int => unit=?,
    ~onSnapToItem: int => unit=?,
    ~loop: bool=?,
    ~inactiveSlideScale: float=?
  ) =>
  React.element =
  "default";