#ifndef _BASE_FUNCTION_H
#define _BASE_FUNCTION_H
#define QTDL_DELETE(ptr)                                                       \
    if (ptr != nullptr)                                                        \
    {                                                                          \
        delete ptr;                                                            \
        ptr = nullptr;                                                         \
    }
#endif // !_BASE_FUNCTION_H
