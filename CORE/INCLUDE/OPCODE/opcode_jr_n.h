#ifndef OPCODE_JR_N_H
#define OPCODE_JR_N_H

#include "opcode_base.h"

class OpCode_Jr_n : public OpCode_Base
{
public:
    OpCode_Jr_n(Cpu& ai_cpu, Mpu& ai_mpu);

    virtual inline uint8_t getId() const {
        return 0x18u;
    }

    virtual inline uint8_t getMask() const {
        return 0xFFu;
    }

    virtual void execute(uint16_t ai_memOffset);

    virtual std::string getInstruction(uint16_t ai_memOffset) const;
};

#endif // OPCODE_JR_N_H
