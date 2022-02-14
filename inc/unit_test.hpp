
#ifndef UNIT_TEST_HPP
# define UNIT_TEST_HPP

#define UNIT_START(name)        std::cout << "\033[0m-> \033[1;32mUnit\033[0m ("name") : " << std::endl; \
                                int errors = 0; \
                                int max_tests = 0; \

#define UNIT_END                if (errors != 0) \
                                    std::cout << "\033[1;31m✗  Unit Failed ! [" << errors << "/" << max_tests << " KO tests]" << std::endl << std::endl; \
                                else \
                                    std::cout << "\033[1;32m✓  Unit Success \033[0m[\033[1;32m" << max_tests << "\033[0m/\033[1;32m" << max_tests << "\033[0m]\033[0m" << std::endl << std::endl;

#define UNIT_TEST(test_name)    max_tests++; std::cout << " . testing " << test_name << std::endl;
#define UNIT_ERROR(error)       errors++; std::cout << "   \033[1;31mERROR\033[0m: " << error << std::endl << std::endl;


#endif