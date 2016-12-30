#ifndef OPCODE_LD_NN_SP_H
#define OPCODE_LD_NN_SP_H

#include "opcode_base.h"


class OpCode_Ld_nn_sp : public OpCode_Base
{
public:
    OpCode_Ld_nn_sp(Cpu &ai_cpu, Mpu &ai_mpu);

    virtual inline uint8_t getId() const {
        return 0x08u;
    }

    virtual inline uint8_t getMask() const {
        return 0xFFu;
    }

    virtual void execute(uint16_t ai_memOffset);

    virtual std::string getInstruction(uint16_t ai_memOffset) const;
};

#endif // OPCODE_LD_NN_SP_H
