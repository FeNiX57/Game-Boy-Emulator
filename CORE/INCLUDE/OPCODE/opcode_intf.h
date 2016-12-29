#ifndef OPCODE_INTF_H
#define OPCODE_INTF_H

#include "CORE/INCLUDE/cpu.h"
#include "CORE/INCLUDE/mpu.h"

class OpCode_Intf {
public:
    virtual ~OpCode_Intf() {

    }

    virtual void execute(uint16_t ai_memOffset) = 0;
    virtual std::string getInstruction(uint16_t ai_memOffset) const = 0;
    virtual uint8_t getId() const = 0;
    virtual uint8_t getMask() const = 0;
};

inline bool operator==(const OpCode_Intf& ai_opCode, uint8_t ai_id) {
    return ((ai_id & ai_opCode.getMask()) == ai_opCode.getId());
}

inline bool operator==(uint8_t ai_id, const OpCode_Intf& ai_opCode) {
    return operator==(ai_opCode, ai_id);
}

#endif // OPCODE_INTF_H
