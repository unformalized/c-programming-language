//
// Created by bytedance on 2020/8/29.
//

/*
 * 宏替换
 * #undef 取消宏定义
 * #, ##
 * 条件包含
 *
 * #ifndef 表示此内容未被定义，我们就可以定义它
 * */

#ifndef CPL_MACRO_H
#define CPL_MACRO_H

#define FOREVER for(;;)
#define MAX(A, B) ((A) > (B) ? (A) : (B))

#undef FOREVER

void sleep()
{
    MAX(1, 2);
    // FOREVER;
}

#endif //CPL_MACRO_H
