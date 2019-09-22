# bs-react-ssr-prepass

BuckleScript bindings for [`react-ssr-prepass`](https://github.com/FormidableLabs/react-ssr-prepass). This allows you to use React `Suspense` for data fetching on the server-side in ReasonML.

## API

These bindings expose a single function, `ssrPrepass`, that allows you to walk your React tree and look for thrown `Promise`s to trigger `Suspense`. The argument passed to this function is a polymorphic variant with two possible constructors.

```reason
[
  | `PrepassNode(React.element)
  | `PrepassNodeVisitor(React.element, visitor)
]
```

If you just want to have `react-ssr-prepass` walk your React tree (or a part of it) and suspend on any thrown `Promise`s, just use the first constructor.

```reason
let prepass = ReactSSRPrepass.ssrPrepass(`PrepassNode(<App />));

prepass
|> Js.Promise.then_(() => {
     Js.log("Prepass has finished. Server render the app!");
     Js.Promise.resolve(() => ());
   });
```

You can also pass a custom `visitor` function to `react-ssr-prepass` that will visit each React element in your application and allow you to execute custom data fetching logic based on the `element`.
