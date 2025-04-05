```
# extract TO_PHONEMIC
farextract automator_phonemic.far

# clone openfst
git clone https://github.com/alphacep/openfst.git
cd openfst

# build openfst with Emscripten
autoreconf -i
emconfigure ./configure --enable-bin=no --enable-grm --enable-static --disable-shared --host none
emmake make -j

# build
em++ -std=c++17 -Wall -lfst -Lopenfst/src/lib/.libs -Iopenfst/src/include \
	--bind -O3 -g1 \
  -s WASM=1 \
  -s SINGLE_FILE=1 \
  -s WASM_ASYNC_COMPILATION=1 \
  -s ALLOW_MEMORY_GROWTH=1 \
  -s DISABLE_EXCEPTION_CATCHING=1 \
  -s AGGRESSIVE_VARIABLE_ELIMINATION=1 \
  -s NO_EXIT_RUNTIME=1 \
  -s ASSERTIONS=0 \
  -s ERROR_ON_UNDEFINED_SYMBOLS=1 \
  -s NODEJS_CATCH_EXIT=0 \
	-s DYNAMIC_EXECUTION=0 \
	-s TEXTDECODER=0 \
	-s ENVIRONMENT='web' \
	-s FETCH_SUPPORT_INDEXEDDB=0 \
  -s EXPORT_ES6=1 \
	-s USE_ES6_IMPORT_META=1 \
  -s EXPORTED_RUNTIME_METHODS=['FS'] \
	-s EXPORT_NAME="processor" \
  -s MODULARIZE=1 \
	-s INCOMING_MODULE_JS_API=['instantiateWasm'] \
	-w \
	binding.cc processor.cc -o processor.js
```
