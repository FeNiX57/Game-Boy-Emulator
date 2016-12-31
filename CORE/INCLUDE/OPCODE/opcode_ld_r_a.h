#ifndef OPCODE_LD_R_A_H
#define OPCODE_LD_R_A_H

#include "opcode_base.h"

class OpCode_Ld_r_a : public OpCode_Base
{
public:
    OpCode_Ld_r_a(Cpu &ai_cpu, Mpu &ai_mpu);

    virtual inline uint8_t getId() const {
        return 0x02u;
    }

    virtual inline uint8_t getMask() const {
        return 0xEFu;
    }

    virtual void execute(uint16_t ai_memOffset);

    virtual std::string getInstruction(uint16_t ai_memOffset) const;
};

#endif // OPCODE_LD_R_A_H
