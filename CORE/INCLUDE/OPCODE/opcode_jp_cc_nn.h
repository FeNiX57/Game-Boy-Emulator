#ifndef OPCODE_JP_CC_NN_H
#define OPCODE_JP_CC_NN_H

#include "opcode_base.h"

class OpCode_Jp_cc_nn : public OpCode_Base
{
public:
    OpCode_Jp_cc_nn(Cpu &ai_cpu, Mpu &ai_mpu);

    virtual inline uint8_t getId() const {
        return 0xE7;
    }

    virtual inline uint8_t getMask() const {
        return 0xC2;
    }

    virtual void execute(uint16_t ai_memOffset);
    virtual std::string getInstruction(uint16_t ai_memOffset) const;
};

#endif // OPCODE_JP_CC_NN_H
