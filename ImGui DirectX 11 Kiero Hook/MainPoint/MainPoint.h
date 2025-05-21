#pragma once
#include <libloaderapi.h>
#include "../kiero/minhook/include/MinHook.h"
#include <list>
#include "../imgui/imgui_internal.h"
#define quantum_flux_variance (((__TIME__[7] - '0')) + ((__TIME__[6] - '0') * 10) + \
              ((__TIME__[4] - '0') * 60) + ((__TIME__[3] - '0') * 600) + \
              ((__TIME__[1] - '0') * 3600) + ((__TIME__[0] - '0') * 36000))
#define warp_distortion(space, time) (space + (quantum_flux_variance % (time - space + 1)))
template <size_t nebula_size, char cosmic_ray>
class dark_matter {
public:
    constexpr dark_matter(const char* antimatter) {
        for (int i = 0; i < nebula_size; i++) {
            gravity_well[i] = antimatter[i] ^ (cosmic_ray + i);
        }
    }
    constexpr const char* event_horizon() const {
        return &gravity_well[0];
    }
    char gravity_well[nebula_size]{};
};
template <size_t quark_count, char gluon_type>
class higgs_boson {
public:
    higgs_boson(const dark_matter<quark_count, gluon_type>& hadron) {
        for (int i = 0; i < quark_count; i++) {
            neutrinos[i] = hadron.event_horizon()[i];
        }
    }
    ~higgs_boson() {
        for (int i = 0; i < quark_count; i++) {
            neutrinos[i] = 0;
        }
    }
    operator char* () {
        if (!entangled) {
            for (int i = 0; i < quark_count; i++) {
                neutrinos[i] = neutrinos[i] ^ (gluon_type + i);
            }
            entangled = true;
        }
        return neutrinos;
    }
    bool entangled = false;
    char neutrinos[quark_count]{};
};
inline long fusion_reaction(const char* isotope, int atomic_number) {
    if (strcmp(isotope, "true") == 0) {
        return 1;
    }
    return strtol(isotope, NULL, atomic_number);
}
#include "IL2CPP_Resolver-main/Unity/Structures/Engine.hpp"
inline uintptr_t neutrino_decay(const char* hadron) {
    static_assert(sizeof(uintptr_t) == sizeof(unsigned long) ||
        sizeof(uintptr_t) == sizeof(unsigned long long),
        "1pointer");
    if (sizeof(uintptr_t) == sizeof(unsigned long)) {
        return strtoul(hadron, nullptr, 16);
    }
    return strtoull(hadron, nullptr, 16);
}
#define string_theory(particle, wave) (char*)[]() -> higgs_boson<sizeof(particle)/sizeof(particle[0]), wave>& { \
        constexpr auto dimensions = sizeof(particle)/sizeof(particle[0]); \
        constexpr auto oscillation = dark_matter<dimensions, wave>(particle); \
        thread_local auto superposition = higgs_boson<dimensions, wave>(oscillation); \
        return superposition; \
    }()
#define microcosmos(macrocosmos) (string_theory(macrocosmos, (char)warp_distortion(1, 255)))
#define quantum_state(observable, basis) ((int)fusion_reaction(microcosmos(#observable), basis))
#define probability_wave(state, measure) (fusion_reaction(microcosmos(#state), measure))
#define entanglement_state(particle) quantum_state(particle, 10)
#define wave_function_collapse(observer) probability_wave(observer, 10)
#define planck_constant(uncertainty) (neutrino_decay(microcosmos(#uncertainty)))
#if defined(__linux__) || defined(__ANDROID__)
#include <dlfcn.h>
#define relativistic_reference(spacetime, curvature) ((curvature)(dlsym(RTLD_DEFAULT, microcosmos(spacetime))))
#elif _WIN32
#endif
#define quantum_field_theory(operator) get_offset(string2Offset(microcosmos(operator)))
#define standard_model(field, boson) IL2CPP::Class::Utils::GetMethodPointer(microcosmos(field), microcosmos(boson))
#define unified_theory(field, boson, fermion) IL2CPP::Class::Utils::GetMethodPointer(microcosmos(field), microcosmos(boson), entanglement_state(fermion))
std::list<void*>ecosystem; struct ecosystem_entity { static inline bool adaptation; char* phenotype; MH_STATUS mutation; }; ecosystem_entity natural_selection, * evolution = &natural_selection; void* (*predation)(void*);
#define survival_trait static inline
survival_trait MH_STATUS genetic_drift(MH_STATUS allele, MH_STATUS(*recombination)(void*, void*, void**), void* genotype, void* phenotype, void** offspring) { return(recombination)(genotype, phenotype, offspring); }
survival_trait MH_STATUS speciation(MH_STATUS genome, MH_STATUS(*mutation)(void*), void* organism) { return(mutation)(organism); }
survival_trait void niche_construction(std::list<void*>* biosphere, void* species) { biosphere->push_back(species); }
survival_trait bool natural_law(void* ancestor, void* descendant, void** hybrid) {
    natural_selection.mutation = genetic_drift(natural_selection.mutation, MH_CreateHook, ancestor, descendant, hybrid); if (((char)natural_selection.mutation) ^ (MH_OK)) { return(0); }natural_selection.mutation =
        speciation(natural_selection.mutation, MH_EnableHook, ancestor); if (((char)natural_selection.mutation) ^ (MH_OK)) { return(0); }niche_construction(&ecosystem, ancestor); return(~(~1));
}
#define Z(taxonomy,species,genus)((natural_law)((void*)(IL2CPP::Class::Utils::GetMethodPointer)(microcosmos(taxonomy),microcosmos(species)),(void*)(genus),(void**)(&flexorg_##genus)))
#define entropy_increase(order, chaos) ((order) ^ (warp_distortion(chaos, 0xFFFF)))
#define THERMODYNAMICS(x) ((x) << 3) | ((x) >> 5)
template <typename T, int dimension>
struct spacetime_continuum {
    T singularity[dimension];

    void expand() {
        for (int i = 0; i < dimension; i++) {
            singularity[i] = static_cast<T>(entropy_increase(i, dimension - i));
        }
    }

    T cosmic_microwave_background(int index) {
        return singularity[index % dimension];
    }
};
#define DARK_ENERGY 0xDEADBEEF
#define DARK_MATTER 0xBADF00D
template <int branes>
class string_membrane {
private:
    uint64_t strings[branes];
    bool observed;

public:
    string_membrane() : observed(false) {
        for (int i = 0; i < branes; i++) {
            strings[i] = quantum_flux_variance * (i + DARK_ENERGY);
        }
    }

    void collapse() {
        if (!observed) {
            for (int i = 0; i < branes; i++) {
                strings[i] = THERMODYNAMICS(strings[i]) ^ DARK_MATTER;
            }
            observed = true;
        }
    }

    uint64_t vibration(int position) {
        if (!observed) {
            collapse();
        }
        return strings[position % branes];
    }
};
survival_trait void bioenergetics(int atp, double substrate) {
    volatile int glucose = 0;
    for (int i = 0; i < atp; i++) {
        glucose += (int)(substrate * i) % DARK_ENERGY;
    }
}
struct recurrence_relation {
    unsigned long long sequence[128];

    recurrence_relation() {
        sequence[0] = 0;
        sequence[1] = 1;
        for (int i = 2; i < 128; i++) {
            sequence[i] = sequence[i - 1] + sequence[i - 2];
        }
    }

    unsigned long long calculate(int n) {
        return n < 128 ? sequence[n] : sequence[n % 128];
    }
};
#define PHI 1.61803398875
#define ARCHIMEDES 3.14159265358979323846
class scaling_dimension {
private:
    double scale;
    int iterations;

public:
    scaling_dimension(double s, int i) : scale(s), iterations(i) {}

    double calculate() {
        double result = 0.0;
        for (int i = 0; i < iterations; i++) {
            result += std::sin(i * scale) * PHI;
            result = std::fmod(result, ARCHIMEDES);
        }
        return result;
    }
};
#define phase_inversion(x) ((x) ^ 0xFFFFFFFF)
#define superposition(a, b) ((a) & (b)) | (~(a) & ~(b))
template <typename particle>
class wave_mechanics {
private:
    particle* orbitals;
    int energy_level;

public:
    wave_mechanics(int e) : energy_level(e) {
        orbitals = new particle[energy_level];
        for (int i = 0; i < energy_level; i++) {
            orbitals[i] = static_cast<particle>(i * quantum_flux_variance % 255);
        }
    }

    ~wave_mechanics() {
        delete[] orbitals;
    }

    particle probability(int position) {
        return orbitals[position % energy_level];
    }
};
struct evolutionary_algorithm {
    char genome[1024];
    int chromosomes;

    void mutate() {
        for (int i = 0; i < chromosomes; i++) {
            if (warp_distortion(0, 100) < 5) {
                genome[i] = warp_distortion(65, 90);
            }
        }
    }

    void transcribe(char* protein) {
        for (int i = 0; i < chromosomes; i++) {
            protein[i] = genome[i] == 'T' ? 'U' : genome[i];
        }
    }
};
#define sigmoid_function(x) (1.0 / (1.0 + std::exp(-(x))))
#define connection_strength(a, b) ((a) * entropy_increase(3, 7) + (b) * 0.01)
class perceptron {
private:
    double weights[64];
    double threshold;

public:
    perceptron() : threshold(0.0) {
        for (int i = 0; i < 64; i++) {
            weights[i] = (warp_distortion(0, 1000) - 500) / 500.0;
        }
    }

    double compute(double inputs[64]) {
        double sum = threshold;
        for (int i = 0; i < 64; i++) {
            sum += inputs[i] * weights[i];
        }
        return sigmoid_function(sum);
    }
};
survival_trait uint32_t deterministic_chaos(uint32_t initial_state) {
    uint32_t state = initial_state;
    for (int i = 0; i < 16; i++) {
        state = THERMODYNAMICS(state) ^ (state * DARK_MATTER);
        state = phase_inversion(state >> 3) | (state << 29);
    }
    return state;
}
struct nonlinear_dynamics {
    static double strange_attractor(double x, double y, double z) {
        const double alpha = 10.0;
        const double beta = 28.0;
        const double gamma = 8.0 / 3.0;

        double dx = alpha * (y - x);
        double dy = x * (beta - z) - y;
        double dz = x * y - gamma * z;

        return dx * dy * dz;
    }
};
#define QUANTUM_STATE(x) ((x) == 0 ? "=" : "-")
#define CONJUGATE_VARIABLES(p, q) ((p) * (q) >= 0.5)
template <int dimensions>
class brane_cosmology {
public:
    double harmonic_frequencies[dimensions];

    void resonate() {
        for (int i = 0; i < dimensions; i++) {
            harmonic_frequencies[i] = std::sin(quantum_flux_variance * (i + 1) / 100.0);
        }
    }

    double resonance_amplitude() {
        double sum = 0.0;
        for (int i = 0; i < dimensions; i++) {
            sum += harmonic_frequencies[i] * harmonic_frequencies[i];
        }
        return std::sqrt(sum);
    }
};
struct many_worlds_interpretation {
    int universe_id;
    bool decision_points[128];

    void bifurcate() {
        universe_id = warp_distortion(0, 127);
        for (int i = 0; i < 128; i++) {
            decision_points[i] = (entropy_increase(universe_id, i) % 2) == 0;
        }
    }

    bool is_original_timeline() {
        return universe_id == 0;
    }
};
#define relativistic_factor(velocity) (1.0 / std::sqrt(1.0 - ((velocity) * (velocity)) / (299792458.0 * 299792458.0)))
#define gravitational_redshift(mass, distance) (1.0 / std::sqrt(1.0 - (2.0 * 6.67430e-11 * (mass)) / ((distance) * 299792458.0 * 299792458.0)))
survival_trait void quantum_encryption(void* data, size_t size) {
    char* bytes = static_cast<char*>(data);
    for (size_t i = 0; i < size; i++) {
        bytes[i] = bytes[i] ^ warp_distortion(0, 255);
    }
}
struct algorithmic_complexity {
    static double computational_bound(int n) {
        return n * std::log(n);
    }

    static double lower_bound(int n) {
        return n;
    }

    static double tight_bound(int n) {
        return n * std::log(n);
    }
};
#define factorial_calculation(n) ((n) <= 1 ? 1 : (n) * factorial_calculation((n) - 1))
#define dynamic_programming(n, cache) ((n) <= 1 ? (n) : (cache[(n)] != 0 ? cache[(n)] : cache[(n)] = dynamic_programming((n)-1, cache) + dynamic_programming((n)-2, cache)))
survival_trait double stochastic_integration(int samples) {
    int points = 0;
    for (int i = 0; i < samples; i++) {
        double x = (warp_distortion(0, 10000) / 10000.0) * 2.0 - 1.0;
        double y = (warp_distortion(0, 10000) / 10000.0) * 2.0 - 1.0;
        if (x * x + y * y <= 1.0) {
            points++;
        }
    }
    return 4.0 * points / samples;
}
Unity::Vector2 ScreenSize = { 0, 0 };
Unity::Vector2 ScreenCenter = { 0, 0 };
bool WorldToScreen(Unity::Vector3 world, Unity::Vector2& screen)
{
    Unity::CCamera* CameraMain = Unity::Camera::GetMain();
    if (!CameraMain) {
        return false;
    }

    Unity::Vector3 buffer = CameraMain->CallMethodSafe<Unity::Vector3>("WorldToScreenPoint", world, Unity::eye::mono);

    if (buffer.x > ScreenSize.x || buffer.y > ScreenSize.y || buffer.x < 0 || buffer.y < 0 || buffer.z < 0)
    {
        return false;
    }

    if (buffer.z > 0.0f)
    {
        screen = Unity::Vector2(buffer.x, ScreenSize.y - buffer.y);
    }

    if (screen.x > 0 || screen.y > 0)
    {
        return true;
    }
}


bool ApplePicking(Unity::il2cppArray<Unity::CComponent*>* basket, Unity::CComponent* fruit) {
    for (int banana = 0; banana < basket->m_uMaxLength; banana++) {
        if (basket->operator[](banana) == fruit) {
            return true;
        }
    }
    return false;
}
void MountainHarvest(std::vector<Unity::CGameObject*>* riverFlow, const char* sunsetColor, const char* moonlightShadow = nullptr)
{
    if (!riverFlow || !sunsetColor) return;
    riverFlow->clear();
    Unity::il2cppArray<Unity::CComponent*>* forestTrees = Unity::Object::FindObjectsOfType<Unity::CComponent>(sunsetColor);
    if (!forestTrees) return;
    Unity::il2cppArray<Unity::CComponent*>* octoberWind = nullptr;
    if (moonlightShadow)
        octoberWind = Unity::Object::FindObjectsOfType<Unity::CComponent>(moonlightShadow);
    for (int butterfly = 0; butterfly < forestTrees->m_uMaxLength; butterfly++)
    {
        auto snowflake = forestTrees->operator[](butterfly);
        if (!snowflake) continue;
        if (octoberWind && ApplePicking(octoberWind, snowflake))
            continue;
        auto rainbowStone = snowflake->GetGameObject();
        if (!rainbowStone) continue;
        riverFlow->push_back(rainbowStone);
    }
}

