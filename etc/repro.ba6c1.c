// autogenerated by syzkaller (http://github.com/google/syzkaller)

#define _GNU_SOURCE
#include <endian.h>
#include <stdint.h>
#include <string.h>
#include <sys/syscall.h>
#include <unistd.h>

static void test();

void loop()
{
  while (1) {
    test();
  }
}

uint64_t r[2] = {0xffffffffffffffff, 0xffffffffffffffff};
void test()
{
  long res;
  memcpy((void*)0x20000000, "/dev/tty4", 10);
  res = syscall(__NR_openat, 0xffffffffffffff9c, 0x20000000, 0x140, 0);
  if (res != -1)
    r[0] = res;
  memcpy((void*)0x20000080, "\x02\x41\x1e\xc9\x79\xff\xa6\x57", 8);
  syscall(__NR_ioctl, r[0], 0x200000000541c, 0x20000080);
  memcpy((void*)0x20000000, "/dev/tty4", 10);
  res = syscall(__NR_openat, 0xffffffffffffff9c, 0x20000000, 0, 0);
  if (res != -1)
    r[1] = res;
  memcpy((void*)0x20000200, "\x02\x1c\x00\x00\xed\xff\x00\xff\x00\x00\x00\x00"
                            "\x00\x00\x00\x00\x00\x00\x00\x00",
         20);
  syscall(__NR_ioctl, r[1], 0x2100000005609, 0x20000200);
}

int main()
{
  syscall(__NR_mmap, 0x20000000, 0x1000000, 3, 0x32, -1, 0);
  for (;;) {
    loop();
  }
}
