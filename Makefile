
CXX_FLAGS = -DBOOST_NO_WREGEX -DHAVE_CONFIG_H \
	-fPIC -std=c++11 -m64 \
	-stdlib=libc++ -fvisibility=hidden -Wall -Wreturn-type -Wunused \
	-Wno-unused-parameter -O3

sdr: test.cpp
	capnp compile -oc++ --src-prefix=example example/proto.capnp
	clang++ -c proto.capnp.c++ $(CXX_FLAGS)
	clang++ -c test.cpp $(CXX_FLAGS)
	clang++ -Wl,-search_paths_first \
		-Wl,-headerpad_max_install_names -Wl,-u,_munmap -m64 \
		-stdlib=libc++ \
		-lc++abi -liconv -lsqlite3 -lkj -lcapnp -framework CoreServices -framework Accelerate \
		proto.capnp.o test.o -o test
