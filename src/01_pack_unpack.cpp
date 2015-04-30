#include <tuple>
#include <string>
#include <sstream>
#include <
#include <msgpack.hpp>

int main() {
    auto t = std::make_tuple("hello", true, 42, 12.3);
    std::stringstream ss;
    msgpack::pack(ss, t);

    msgpack::unpacked unpacked
        = msgpack::unpack(ss.str().data(), ss.str().size());
    msgpack::object obj = unpacked.get();
    auto tt = obj.as<std::tuple<std::string, bool, int, double>>();
    assert(t == tt);
}

