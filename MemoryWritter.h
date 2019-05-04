#pragma once
#include <new>
#include <string.h>
#include <stdio.h>

using namespace std;
class MemoryWritter
{

private:
    char *backup;
    int position;
    size_t size;
    
public:
    char buffer[4190];
    MemoryWritter(int bufferSize)
    {
        //this->buffer = new char[bufferSize];
        this->position = 6;
        this->size = 0;
    }

    void Resize(int size)
    {
        //this->backup = this->buffer;
        //this->buffer = new char[size];
        memcpy(this->buffer, this->backup, (size_t)size);
    }

    void AddLength(int size)
    {
        WriteInt16(this->size + size, 0);

        this->position += size;
    }

    void ZeroBuffer(int size)
    {
        for(int i = 0; i < size; i++)
        {
            buffer[i] = 0;
        }
    }

    void Reset()
    {
        //this->buffer = new char[0];
        this->position = 6;
        this->size = 0;
    }

    int * GetBuffer()
    {
        return (int*)&buffer[0];
    }

    size_t GetSize()
    {
        return this->size;
    }

    int GetPosition()
    {
        return this->position;
    }

    void WriteUByte(unsigned char value)
    {
        this->buffer[this->position] = (unsigned char)value;

        this->size++;
        this->AddLength(1);
    }

    void WriteByte(char value)
    {
        
        buffer[this->position] = value;
        
        size++;
        this->AddLength(1);
    }

  
    void WriteUInt16(unsigned short value)
    {
        memcpy(this->buffer + this->position, (void*)value, 2);
        
        this->size += 2;
        
        this->AddLength(2);
    }

    void WriteInt16(short value)
    {
        memcpy(&buffer[position], &value, 2);
        
        size += 2;
        
        this->AddLength(2);
    }

    void WriteInt16(short value, int offset)
    {
        memcpy(&buffer[offset], &value, 2);
    }

    void WriteInt32(int value)
    {
        memcpy((void*)(this->buffer[this->position]), (void*)value, 2);
        
        this->size += 4;
        
        this->AddLength(4);
    }

    void WriteUint32(unsigned int value)
    {
        memcpy((void*)(this->buffer[this->position]), (void*)value, 2);
        
        this->size += 4;
        
        this->AddLength(4);
    }
    

    void WriteString(string text, int size)
    {

        const char *msg = text.c_str();

        memcpy(&buffer[position], msg, (size_t)size);

        this->size += size;
        
        this->AddLength(size);
    }


};
