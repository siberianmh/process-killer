# Win Process Killer

> Kill Windows process by name.

## Install

```sh
$ npm install --save win-process-killer
# or
$ yarn add win-process-killer
```

## Usage

```js
const processKiller = require('win-process-killer')

;(() => {
  const killed = processKiller.killProcessByName('notepad.exe')
  console.log(killed) // => returns `true` if killed or `false` if `no`
})()
```

## API

`killProcessByName(name)`

Arguments:

- name `String` (required)

Returns `Boolean`, `true` if process successfuly killed or `false` if no.

## License

MIT
