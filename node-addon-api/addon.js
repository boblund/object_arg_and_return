var addon = require('bindings')('addon');

let r = addon({
	aString: "some string",
	anArray: Uint16Array.from([800, 600]),
	aBoolean: true
});

console.log(r);
