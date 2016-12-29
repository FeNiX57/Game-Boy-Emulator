#ifndef OPCODE_NOP_H
#define OPCODE_NOP_H

#include "opcode_base.h"

class OpCode_Nop : public OpCode_Base
{
public:
    OpCode_Nop(Cpu& ai_cpu, Mpu& ai_mpu);

    virtual inline uint8_t getId () const {
        return 0x00u;
    }

    virtual inline uint8_t getMask() const {
        return 0xFFu;
    }

    virtual void execute(uint16_t ai_memOffset);
    virtual std::string getInstruction(uint16_t ai_memOffset) const;

};

#endif // OPCODE_NOP_H
