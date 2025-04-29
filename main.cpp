#include <iostream>
#include <asio.hpp>
#include <asio/ip/tcp.hpp>

using asio::ip::tcp;

// 处理客户端连接
void handle_connection(tcp::socket socket) {
    try {
        std::array<char, 128> buffer;
        asio::error_code error;

        // 读取客户端数据
        size_t length = socket.read_some(asio::buffer(buffer), error);
        if (!error) {
            // 将数据写回客户端
            asio::write(socket, asio::buffer(buffer, length), error);
        }
    }
    catch (std::exception& e) {
        std::cerr << "Exception in thread: " << e.what() << std::endl;
    }
}

int main() {
    try {
        std::cerr << "Exception in aaaaaaaaaaaaaaaaaaaaathread: " ;
        asio::io_context io_context;
        tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), 12345));

        for (;;) {
            // 接受客户端连接
            tcp::socket socket(io_context);
            acceptor.accept(socket);
            // 处理连接
            handle_connection(std::move(socket));
        }
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
    