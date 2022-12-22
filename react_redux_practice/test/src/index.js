import React from "react";
import * as ReactDOM from "react-dom/client";
import App from "./components/App";
import counterApp from './reducers';

const appElement = ReactDOM.createRoot(document.getElementById('app'));

appElement.render(
  <React.StrictMode>
      <App />
  </React.StrictMode>
);
counterApp();