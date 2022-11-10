#pragma once

template <typename T>
class Singleton
{
public:
    Singleton(){};
    virtual ~Singleton(){};

public:
    static T *Instance()
    {
        static T *instance = new T();
        return instance;
    }
};
