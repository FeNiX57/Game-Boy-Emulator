#include "CORE/INCLUDE/OPCODE/opcode_ld_r_nn.h"

#include <sstream>

OpCode_Ld_r_nn::OpCode_Ld_r_nn(Cpu& ai_cpu, Mpu& ai_mpu) : OpCode_Base(ai_cpu, ai_mpu)
{

}

void OpCode_Ld_r_nn::execute(uint16_t ai_memOffset)
{
    _decodeAndSetRegister16Bits(ai_memOffset, _get16BitData(ai_memOffset));
    m_cpu.setRegisterPC(m_cpu.getRegisterPC() + 3u);
}

std::string OpCode_Ld_r_nn::getInstruction(uint16_t ai_memOffset) const
{
    std::stringstream w_sstream;
    w_sstream << "LD R, nn\t(R = " << _decodeAndGetNameRegister16Bits(ai_memOffset) << ", nn = 0x" << std::hex << _get16BitData(ai_memOffset) << ")";
    return w_sstream.str();
}

