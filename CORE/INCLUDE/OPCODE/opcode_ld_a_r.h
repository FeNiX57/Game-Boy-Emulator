#ifndef OPCODE_LD_A_R_H
#define OPCODE_LD_A_R_H

#include "opcode_base.h"

class OpCode_Ld_a_r : public OpCode_Base
{
public:
    OpCode_Ld_a_r(Cpu &ai_cpu, Mpu &ai_mpu);

    virtual inline uint8_t getId() const {
        return 0x0Au;
    }

    virtual inline uint8_t getMask() const {
        return 0xEFu;
    }

    virtual void execute(uint16_t ai_memOffset);

    virtual std::string getInstruction(uint16_t ai_memOffset) const;
};

#endif // OPCODE_LD_A_R_H
