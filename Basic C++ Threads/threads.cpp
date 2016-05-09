
#include <string>
#include <iostream>
#include <thread>

#include "sync_queue.cpp"

std::mutex g_lock;

void producer(synchronized_queue<std::string>& queue) {
    int count = 0;

    while(true) {
        if (queue.size() < 10) {
            queue.add("Value-" + std::to_string(count));
            count++;
        } else {
            std::this_thread::yield();
        }
    }
}

void defaultConsumer(synchronized_queue<std::string>& queue) {

    while(true) {
        if(queue.size() > 0) {
            std::string value = queue.removeOrDefault("");

            if (value.size() > 0) {
                // synchronize access to output
                std::lock_guard<std::mutex> lock(g_lock);
                std::cout << "Retrieved: " << value << std::endl;
            }
        } else {
            std::this_thread::yield();
        }
    }
}

void blockingConsumer(synchronized_queue<std::string>& queue) {

    while(true) {
        std::string value = queue.removeBlocking();

        // synchronize access to output
        std::lock_guard<std::mutex> lock(g_lock);
        std::cout << "Retrieved: " << value << std::endl;
    }
}

void throwingConsumer(synchronized_queue<std::string>& queue) {

    while(true) {
        try {
            std::string value = queue.remove();

            // synchronize access to output
            std::lock_guard<std::mutex> lock(g_lock);
            std::cout << "Retrieved: " << value << std::endl;
        } catch (...) {
            // ignore
        }
    }
}

int main(int argc, char* argv[]) {

    synchronized_queue<std::string> queue;

    std::thread thread_producer(producer, std::ref(queue));
    std::thread default_consumer(defaultConsumer, std::ref(queue));

    std::thread thread_producer2(producer, std::ref(queue));
    std::thread blocking_consumer(blockingConsumer, std::ref(queue));

    std::thread thread_producer3(producer, std::ref(queue));
    std::thread throwing_consumer(throwingConsumer, std::ref(queue));

    thread_producer.join();
    default_consumer.join();

    thread_producer2.join();
    blocking_consumer.join();

    thread_producer3.join();
    throwing_consumer.join();




    return 0;
}
