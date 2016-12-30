#ifndef OPCODE_LD_R_NN_H
#define OPCODE_LD_R_NN_H

#include "opcode_base.h"

class OpCode_Ld_r_nn : public OpCode_Base
{
public:
    OpCode_Ld_r_nn(Cpu &ai_cpu, Mpu &ai_mpu);

    virtual inline uint8_t getId() const {
        return 0x01u;
    }

    virtual inline uint8_t getMask() const {
        return 0xCFu;
    }

    virtual void execute(uint16_t ai_memOffset);
    virtual std::string getInstruction(uint16_t ai_memOffset) const;

};

#endif // OPCODE_LD_R_NN_H
