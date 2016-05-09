
#include <vector>
#include <mutex>
#include <exception>

template <class T>
class synchronized_queue {

    std::vector<T> items;
    std::mutex lock;

public:

    void add(T element) {
        lock.lock();
        items.push_back(element);
        lock.unlock();
    }

    /*
     * Threaded removal of values causes an interesting challenge. The threaded code can check if the queue has items
     * to remove, but without using the same mutex to synchronize access those items MAY have already been removed
     * when the thread actually calls to remove them. This is a problem if there are no longer any items in the queue
     * when the thread tries to remove one. By allowing a default value the calling thread can check the result to see
     * if it was given the default. Not exactly an elegant solution... but it works.
     */
    T removeOrDefault(T defaultValue) {
        lock.lock();
        T result;
        if (items.size() > 0) {
            // Vector causes undefined behavior if it is empty
            result = items.back();
            items.pop_back();
        } else {
            result = defaultValue;
        }
        lock.unlock();

        return result;
    }

    /*
     * An alternative approach to threaded removal is to intentionally block the thread until an item can be removed
     * from the queue. This is useful if you can guarentee that an item will be added in the future and that you can
     * wait an arbitrary amount of time for it.
     */
    T removeBlocking() {

        bool hasResult = false;

        T result;
        while(hasResult == false) {
            lock.lock();
            // Vector causes undefined behavior if it is empty
            if (items.size() > 0) {
                result = items.back();
                items.pop_back();
                lock.unlock();
                hasResult = true;
            } else {
                // item is not present, give up lock and yield thread so queue can be checked later
                lock.unlock();
                std::this_thread::yield();
            }
        }

        return result;
    }

    /*
     * Another way of handling this is to throw an exception if there is no item present. This seems a bit off, as it
     * really isn't an "exceptional" circumstance, as this is really just a way of signaling a particular case. Still
     * a workable option though.
     */
    T remove() {
        // This will automatically be destroyed (freeing the lock) if there is an exception
        std::lock_guard<std::mutex> l(lock);

        T result;
        if (items.size() > 0) {
            // Vector causes undefined behavior if it is empty
            result = items.back();
            items.pop_back();
        } else {
            throw NotFoundException();
        }

        return result;
    }

    std::size_t size() {
        return items.size();
    }

    class NotFoundException : public std::exception {

        virtual const char* what() const throw() {
            return "Not Found";
        }
    };

};
