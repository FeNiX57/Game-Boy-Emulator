#ifndef OPCODE_JP_HL_H
#define OPCODE_JP_HL_H

#include "opcode_base.h"


class OpCode_Jp_hl : public OpCode_Base
{
public:
    OpCode_Jp_hl(Cpu &ai_cpu, Mpu &ai_mpu);

    virtual inline uint8_t getId() const {
        return 0xE9u;
    }

    virtual inline uint8_t getMask() const {
        return 0xFFu;
    }

    virtual void execute(uint16_t ai_memOffset);

    virtual std::string getInstruction(uint16_t ai_memOffset) const;
};

#endif // OPCODE_JP_HL_H
