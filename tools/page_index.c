#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "用法：%s <64位整数（十进制或十六进制，例：0x1234abcd]> \n", argv[0]);
        return 1;
    }

    // 自动识别十进制或十六进制
    char *endptr = NULL;
    uint64_t value = strtoull(argv[1], &endptr, 0);
    if (*endptr != '\0') {
        fprintf(stderr, "无法解析输入 '%s' 为整型。\n", argv[1]);
        return 1;
    }

    // 提取每一段的 9 位
    uint64_t part1 = (value >> 39) & 0x1FF; // [47:39]
    uint64_t part2 = (value >> 30) & 0x1FF; // [38:30]
    uint64_t part3 = (value >> 21) & 0x1FF; // [29:21]
    uint64_t part4 = (value >> 12) & 0x1FF; // [20:12]

    // 输出结果
    printf("输入值: 0x%016" PRIx64 " (%" PRIu64 ")\n", value, value);
    printf("[47:39] = 0x%03" PRIx64 " (%" PRIu64 ")\n", part1, part1);
    printf("[38:30] = 0x%03" PRIx64 " (%" PRIu64 ")\n", part2, part2);
    printf("[29:21] = 0x%03" PRIx64 " (%" PRIu64 ")\n", part3, part3);
    printf("[20:12] = 0x%03" PRIx64 " (%" PRIu64 ")\n", part4, part4);

    return 0;
}

