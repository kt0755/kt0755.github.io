// autogenerated by syzkaller (http://github.com/google/syzkaller)

#define _GNU_SOURCE
#include <endian.h>
#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/syscall.h>
#include <unistd.h>

static uintptr_t syz_open_dev(uintptr_t a0, uintptr_t a1, uintptr_t a2)
{
  if (a0 == 0xc || a0 == 0xb) {
    char buf[128];
    sprintf(buf, "/dev/%s/%d:%d", a0 == 0xc ? "char" : "block", (uint8_t)a1,
            (uint8_t)a2);
    return open(buf, O_RDWR, 0);
  } else {
    char buf[1024];
    char* hash;
    strncpy(buf, (char*)a0, sizeof(buf));
    buf[sizeof(buf) - 1] = 0;
    while ((hash = strchr(buf, '#'))) {
      *hash = '0' + (char)(a1 % 10);
      a1 /= 10;
    }
    return open(buf, a2, 0);
  }
}

uint64_t r[1] = {0xffffffffffffffff};
void loop()
{
  long res;
  res = syz_open_dev(0xc, 1, 4);
  if (res != -1)
    r[0] = res;
  syscall(__NR_read, r[0], 0x20000280, 0x44);
  memcpy((void*)0x200001c0,
         "\x18\x4e\x3b\xac\x74\x54\x18\x8a\x9f\x3c\x0f\xd8\x54\x84\x8e\x29\x49"
         "\x12\x64\x16\xeb\x3b\xf7\x8a\x27\xdc\xac\x09\x76\x1f\xbb\x0f\xf8\xbc"
         "\xf4\x10\x13\x64\xe2\xb8\x5c\xc3\xf4\x60\x1d\x3c\x1e\xf4\x7e\x01\x52"
         "\xee\x41\xf7\x60\xcf\xf6\x15\x21\x09\x42\xc8\xfc\x4e\x7b\x19\x67\x2f"
         "\xe1\xfa\xfb\x37\x95\xc0\xa2\xc4\x2e\xa7\xb4\x26\xc9\x47\xa8\x1c\x7e"
         "\xfe\xf2\xf8\x4e\x21\xe7\xd3\x2b\x5a\xf0\x6a\xbc\xa3\xc0\xb7\x64\xf5"
         "\xc4\x95\x79\xe0\xd1\x2f\x04\xaa\x31\x7d\x7f\x3b\x2c\xba\x4d\x5e\xa3"
         "\x4e\xec\xca\x60\x09\x5e\xeb\xbf\x29\x71\x3f\x33\x61\x4a\xb9\xd3\x08"
         "\xd4\xc0\xf7\x09\xf4\x86\xbd\xbe\x93\x09\x8f\x80\x72\x5f\x5a\xda\x5c"
         "\x8e\xcd\x90\x42\xda\xa1\x93\x3a\x47\x54\x10\xe7\x77\x25\xe0\x72\xf0"
         "\xf0\x26\x2a\xf9\x47\xb2\x0f\x19",
         178);
  syscall(__NR_write, r[0], 0x200001c0, 0xb2);
  memcpy((void*)0x20000000, "\xf3\xb0\xad\xda\x06\x00\x00\x00\x00\x00\x00\x00"
                            "\xa2\x24\xe1\x5e\x47\x8f\x2f\xd3",
         20);
  syscall(__NR_write, -1, 0x20000000, 0x14);
  syz_open_dev(0xc, 0x2915, 0);
  syz_open_dev(0xc, 1, 0x40);
}

int main()
{
  syscall(__NR_mmap, 0x20000000, 0x1000000, 3, 0x32, -1, 0);
  loop();
  return 0;
}

