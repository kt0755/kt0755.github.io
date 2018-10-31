
#define _GNU_SOURCE
#include <endian.h>
#include <stdint.h>
#include <string.h>
#include <sys/syscall.h>
#include <unistd.h>

uint64_t r[1] = {0xffffffffffffffff};
void loop()
{
  long res;
  memcpy((void*)0x20002880, "/dev/ppp", 9);
  res = syscall(__NR_open, 0x20002880, 2, 0);
  if (res != -1)
    r[0] = res;
  memcpy((void*)0x20000080, "\xff\xff\xff\x7f\x00\x00\x00\x00\x00\x00\xd3\x0e"
                            "\x5f\xd3\xd1\xd8\x48\xc8\x09\xbe\x91\x28\x6e\x64"
                            "\x37\x33\x0d\x1f\x32\x5e",
         30);
  syscall(__NR_ioctl, r[0], 0xc004743e, 0x20000080);
}

int main()
{
  syscall(__NR_mmap, 0x20000000, 0x1000000, 3, 0x32, -1, 0);
  loop();
  return 0;
}

