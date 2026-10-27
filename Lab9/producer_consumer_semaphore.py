import threading
import queue
import time

Size = 5
buffer = queue.QUEUE(Size)

empty = threading.Semaphore(Size)
full = threading.Semaphore(0)
mutex = threading.lock()

def Producer():
    for i in range(1,11):
        empty.acquire()
        with mutex:
            buffer.put(i)
            print("Produced :",i)
        full.release()
        time.sleep(0.2)

def Consumer():
    for i in range(1,11):
        full.acquire()
        with mutex:
            item = buffer.get()
            print("Consumed : ",item)
        empty.release()
        time.sleep(0.2)

p = threading.Thread(target = Producer)
q = threading.Thread(target = Consumer)

p.start()
q.start()

p.join()
q.join()

print("Finished")