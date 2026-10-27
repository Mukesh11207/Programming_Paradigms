import threading
import time

class TestAndSetLock():
    def __init__(self):
        self._lock=threading.Lock()
        self._flag=False

    def test_and_set(self):
        with self._lock:
            self.old_flag=self._flag
            self._flag=True
            return self.old_flag

    def acquire(self):
        while self.test_and_set():
            time.sleep(0.5)

    def release(self):
        with self._lock:
            self._flag=False

def worker(name, lock):
    lock.acquire()
    try:
        print(f'{name} acquired the lock')
        print(f'{name} is in critical section')
        time.sleep(0.5)
    finally:
        lock.release()
        print(f'{name} released the lock')

lock=TestAndSetLock()
t1=threading.Thread(target=worker, args=('Thread1', lock))
t2=threading.Thread(target=worker, args=('Thread2', lock))

t1.start()
t2.start()
t1.join()
t2.join()