type t = Js.Promise.t(unit);

type visitor = React.element => Js.Nullable.t(Js.Promise.t(Js.Json.t));

[@bs.module]
external ssrPrepass:
  (
  [@bs.unwrap]
  [
    | `PrepassNode(React.element)
    | `PrepassNodeVisitor(React.element, visitor)
  ]
  ) =>
  t =
  "react-ssr-prepass";