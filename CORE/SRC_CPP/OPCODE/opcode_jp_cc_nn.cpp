#include "CORE/INCLUDE/OPCODE/opcode_jp_cc_nn.h"

#include <sstream>

OpCode_Jp_cc_nn::OpCode_Jp_cc_nn(Cpu& ai_cpu, Mpu& ai_mpu) : OpCode_Base(ai_cpu, ai_mpu)
{

}

void OpCode_Jp_cc_nn::execute(uint16_t ai_memOffset)
{
    if (_decodeAndTestCondition(ai_memOffset)) {
        m_cpu.setRegisterPC(_get16BitData(ai_memOffset));
    }
    else {
        m_cpu.setRegisterPC(m_cpu.getRegisterPC() + 3u);
    }
}

std::string OpCode_Jp_cc_nn::getInstruction(uint16_t ai_memOffset) const
{
    std::stringstream w_sstream;
    w_sstream << "JP CC, NN\t(CC = " << _decodeAndGetNameCondition(ai_memOffset);
    w_sstream << ", NN = " << std::hex << "0x" << _get16BitData(ai_memOffset) << ")\t";
    if (_decodeAndTestCondition(ai_memOffset)) {
        w_sstream << "(VALID)";
    }
    else {
        w_sstream << "(NOT VALID)";
    }
    return w_sstream.str();
}
