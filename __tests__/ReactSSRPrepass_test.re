let _ = ReactSSRPrepass.ssrPrepass(`PrepassNode(<App />));
let _ =
  ReactSSRPrepass.ssrPrepass(
    `PrepassNodeVisitor((
      <App />,
      element => {
        Js.log2("Element found: ", element);
        Js.Nullable.undefined;
      },
    )),
  );

let prepass = ReactSSRPrepass.ssrPrepass(`PrepassNode(<App />));
prepass
|> Js.Promise.then_(() => {
     Js.log("Prepass has finished.");
     Js.Promise.resolve(() => ());
   });