#include "CORE/INCLUDE/OPCODE/opcode_base.h"

OpCode_Base::OpCode_Base(Cpu &ai_cpu, Mpu &ai_mpu) : m_cpu(ai_cpu), m_mpu(ai_mpu)
{
}

uint8_t OpCode_Base::_decodeAndGetRegister8Bits(uint8_t ai_register) const
{
    switch (ai_register)
    {
        case 0:
            return m_cpu.getRegisterB();

        case 1:
            return m_cpu.getRegisterC();

        case 2:
            return m_cpu.getRegisterD();

        case 3:
            return m_cpu.getRegisterE();

        case 4:
            return m_cpu.getRegisterH();

        case 5:
            return m_cpu.getRegisterL();

        case 6:
            return m_mpu.getMemVal(m_cpu.getRegisterHL());

        case 7:
            return m_cpu.getRegisterA();

        default:
            std::cout << "ERREUR : Registre 8 bits inconnu" << std::endl;
            return 0;
    }
}

void OpCode_Base::_decodeAndSetRegister8Bits(uint8_t ai_register, uint8_t ai_value)
{
    switch (ai_register)
    {
        case 0:
            m_cpu.setRegisterB(ai_value);

        case 1:
            m_cpu.setRegisterC(ai_value);

        case 2:
            m_cpu.setRegisterD(ai_value);

        case 3:
            m_cpu.setRegisterE(ai_value);

        case 4:
            m_cpu.setRegisterH(ai_value);

        case 5:
            m_cpu.setRegisterL(ai_value);

        case 6:
            return m_mpu.setMemVal(m_cpu.getRegisterHL(), ai_value);

        case 7:
            m_cpu.setRegisterA(ai_value);

        default:
            std::cout << "ERREUR : Registre 8 bits inconnu" << std::endl;
    }
}

std::string OpCode_Base::_decodeAndGetNameRegister8Bits(uint8_t ai_register) const
{
    std::string w_res;
    switch (ai_register)
    {
        case 0:
            w_res = "B";

        case 1:
            w_res = "C";

        case 2:
            w_res = "D";

        case 3:
            w_res = "E";

        case 4:
            w_res = "H";

        case 5:
            w_res = "L";

        case 6:
            w_res = "(HL)";

        case 7:
            w_res = "A";

        default:
            std::cout << "ERREUR : Registre 8 bits inconnu" << std::endl;
            w_res = "UNKNOWN";
    }
    return w_res;
}

uint16_t OpCode_Base::_decodeAndGetRegister16Bits(uint8_t ai_register) const
{
    switch (ai_register) {
        case 0:
            return m_cpu.getRegisterBC();

        case 1:
            return m_cpu.getRegisterDE();

        case 2:
            return m_cpu.getRegisterHL();

        case 3:
            return m_cpu.getRegisterSP();

        default:
            std::cout << "ERREUR : Registre 16 bits inconnu" << std::endl;
            return 0;
    }
}

void OpCode_Base::_decodeAndSetRegister16Bits(uint8_t ai_register, uint16_t ai_value)
{
    switch (ai_register) {
        case 0:
            m_cpu.setRegisterBC(ai_value);

        case 1:
            m_cpu.setRegisterDE(ai_value);

        case 2:
            m_cpu.setRegisterHL(ai_value);

        case 3:
            m_cpu.setRegisterSP(ai_value);

        default:
            std::cout << "ERREUR : Registre 16 bits inconnu" << std::endl;
    }
}

std::string OpCode_Base::_decodeAndGetNameRegister16Bits(uint8_t ai_register) const
{
    std::string w_res;
    switch (ai_register) {
        case 0:
            w_res = "BC";

        case 1:
            w_res = "DE";

        case 2:
            w_res = "HL";

        case 3:
            w_res = "SP";

        default:
            std::cout << "ERREUR : Registre 16 bits inconnu" << std::endl;
            w_res = "";
    }
    return w_res;
}
