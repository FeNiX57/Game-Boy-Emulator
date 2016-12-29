#include "CORE/INCLUDE/OPCODE/opcode_jp_cc_nn.h"

#include <sstream>

OpCode_Jp_cc_nn::OpCode_Jp_cc_nn(Cpu& ai_cpu, Mpu& ai_mpu) : OpCode_Base(ai_cpu, ai_mpu)
{

}

void OpCode_Jp_cc_nn::execute(uint16_t ai_memOffset)
{
    uint8_t w_mnemo = (m_mpu.getMemVal(ai_memOffset) & 0x18) >> 3u;
    bool w_test = true;
    switch (w_mnemo) {
    case 0:
        w_test = (m_cpu.getFlagZ() == 0u);
        break;

    case 1:
        w_test = (m_cpu.getFlagZ() == 1u);
        break;

    case 2:
        w_test = (m_cpu.getFlagC() == 0u);
        break;

    case 3:
        w_test = (m_cpu.getFlagC() == 1u);
        break;

    default:
        std::cerr << "Impossible w_mnemo: " << w_mnemo << std::endl;
        w_test = false;
    }

    if (w_test) {
        m_cpu.setRegisterPC((static_cast<uint16_t>(m_mpu.getMemVal(ai_memOffset+2)) << 8u) + static_cast<uint16_t>(m_mpu.getMemVal(ai_memOffset+1)));
    }
    else {
        m_cpu.setRegisterPC(m_cpu.getRegisterPC() + 3u);
    }
}

std::string OpCode_Jp_cc_nn::getInstruction(uint16_t ai_memOffset) const
{
    std::stringstream w_sstream;
    uint8_t w_mnemo = (m_mpu.getMemVal(ai_memOffset) & 0x18) >> 3u;
    bool w_test = true;
    w_sstream << "JP ";
    switch (w_mnemo) {
    case 0:
        w_test = (m_cpu.getFlagZ() == 0u);
        w_sstream << "NZ, ";
        break;

    case 1:
        w_test = (m_cpu.getFlagZ() == 1u);
        w_sstream << "Z, ";
        break;

    case 2:
        w_test = (m_cpu.getFlagC() == 0u);
        w_sstream << "NC, ";
        break;

    case 3:
        w_test = (m_cpu.getFlagC() == 1u);
        w_sstream << "C, ";
        break;

    default:
        std::cerr << "Impossible w_mnemo: " << w_mnemo << std::endl;
        w_test = false;
    }

    w_sstream << std::hex << "0x" << ((static_cast<uint16_t>(m_mpu.getMemVal(ai_memOffset+2)) << 8u) + static_cast<uint16_t>(m_mpu.getMemVal(ai_memOffset+1))) << "\t";

    if (w_test) {
        w_sstream << "(VALID)";
    }
    else {
        w_sstream << "(NOT VALID)";
    }
    return w_sstream.str();
}
