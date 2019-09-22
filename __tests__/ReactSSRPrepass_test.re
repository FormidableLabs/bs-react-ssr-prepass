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