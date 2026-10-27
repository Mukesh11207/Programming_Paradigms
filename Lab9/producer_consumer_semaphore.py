import threading
import queue
import time

SIZE = 5
buffer = queue.Queue(maxsize = SIZE)

empty = threading.Semaphore(SIZE)
full = threading.Semaphore(0)
mutex = threading.Lock()

def producer():
    for i in range(1,11):
        empty.acquire()
        with mutex:
            buffer.put(i)
            print("Produced :",i)
        full.release()
        time.sleep(0.2)

def consumer():
    for i in range(1,11):
        full.acquire()
        with mutex:
            item = buffer.get()
            print("Consumed :",item)
        empty.release()
        time.sleep(0.2)

p = threading.Thread(target = producer)
c = threading.Thread(target = consumer)

p.start()
c.start()

p.join()
c.join()

print("Finished")