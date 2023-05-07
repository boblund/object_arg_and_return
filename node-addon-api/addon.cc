#include <napi.h>
#include <iostream>

Napi::Object PassObject(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();

	// Process JS object

  Napi::Object obj = info[0].As<Napi::Object>();
  std::cout << "aString: "
		<< obj.Get("aString").ToString().Utf8Value().c_str() << std::endl;
	
	Napi::Uint16Array uint16Array = obj.Get("anArray").As<Napi::Uint16Array>();
	std::cout << "anArray: {" << uint16Array[0] << ", " << uint16Array[1]
		<< "}" << std::endl;

	std::cout << "aBoolean: "
		<< (obj.Get("aBoolean").ToBoolean() ? "true" : "false") << std::endl;
	
	// Return new Napi::Object as JS object

	Napi::Object newObj = Napi::Object::New(env);
	newObj.Set("a_string", "a string");
	Napi::Uint16Array anArray = Napi::Uint16Array::New(env, 2);
	anArray[0] = 10;
	anArray[1] = 20;
	newObj.Set("an_array", anArray);
	newObj.Set("a_boolean", Napi::Boolean::New(env, 1));
	return newObj;
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  return Napi::Function::New(env, PassObject);
}

NODE_API_MODULE(addon, Init)
