/*
 * Copyright (c) 2024 EdgeImpulse Inc.
 *
 * Generated by Edge Impulse and licensed under the applicable Edge Impulse
 * Terms of Service. Community and Professional Terms of Service
 * (https://docs.edgeimpulse.com/page/terms-of-service) or Enterprise Terms of
 * Service (https://docs.edgeimpulse.com/page/enterprise-terms-of-service),
 * according to your product plan subscription (the “License”).
 *
 * This software, documentation and other associated files (collectively referred
 * to as the “Software”) is a single SDK variation generated by the Edge Impulse
 * platform and requires an active paid Edge Impulse subscription to use this
 * Software for any purpose.
 *
 * You may NOT use this Software unless you have an active Edge Impulse subscription
 * that meets the eligibility requirements for the applicable License, subject to
 * your full and continued compliance with the terms and conditions of the License,
 * including without limitation any usage restrictions under the applicable License.
 *
 * If you do not have an active Edge Impulse product plan subscription, or if use
 * of this Software exceeds the usage limitations of your Edge Impulse product plan
 * subscription, you are not permitted to use this Software and must immediately
 * delete and erase all copies of this Software within your control or possession.
 * Edge Impulse reserves all rights and remedies available to enforce its rights.
 *
 * Unless required by applicable law or agreed to in writing, the Software is
 * distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND,
 * either express or implied. See the License for the specific language governing
 * permissions, disclaimers and limitations under the License.
 */
#ifndef __EI_ARM_CMSIS_DSP__H__
#define __EI_ARM_CMSIS_DSP__H__

#include "edge-impulse-sdk/CMSIS/DSP/Include/arm_const_structs.h"
#include "edge-impulse-sdk/CMSIS/DSP/Include/arm_math.h"
#include "edge-impulse-sdk/CMSIS/DSP/Include/dsp/transform_functions.h"
#include "edge-impulse-sdk/dsp/memory.hpp"
#include "edge-impulse-sdk/dsp/numpy_types.h"
#include "edge-impulse-sdk/dsp/returntypes.hpp"


namespace ei {

namespace fft {

/**
* Initialize a CMSIS-DSP fast rfft structure
* We do it this way as this means we can compile out fast_init calls which hints the compiler
* to which tables can be removed
*/
static int cmsis_rfft_init_f32(arm_rfft_fast_instance_f32 *rfft_instance, const size_t n_fft)
{
// ARM cores (ex M55) with Helium extensions (MVEF) need special treatment (Issue 2843)
#if EI_CLASSIFIER_HAS_FFT_INFO == 1 && !defined(ARM_MATH_MVEF) &&                                  \
    !defined(EI_CLASSIFIER_LOAD_ALL_FFTS)
    arm_status status;
    switch (n_fft) {
#if EI_CLASSIFIER_LOAD_FFT_32 == 1
    case 32: {
        arm_cfft_instance_f32 *S = &(rfft_instance->Sint);
        S->fftLen = 16U;
        S->pTwiddle = NULL;
        S->bitRevLength = arm_cfft_sR_f32_len16.bitRevLength;
        S->pBitRevTable = arm_cfft_sR_f32_len16.pBitRevTable;
        S->pTwiddle = arm_cfft_sR_f32_len16.pTwiddle;
        rfft_instance->fftLenRFFT = 32U;
        rfft_instance->pTwiddleRFFT = (float32_t *)twiddleCoef_rfft_32;
        status = ARM_MATH_SUCCESS;
        break;
    }
#endif
#if EI_CLASSIFIER_LOAD_FFT_64 == 1
    case 64: {
        arm_cfft_instance_f32 *S = &(rfft_instance->Sint);
        S->fftLen = 32U;
        S->pTwiddle = NULL;
        S->bitRevLength = arm_cfft_sR_f32_len32.bitRevLength;
        S->pBitRevTable = arm_cfft_sR_f32_len32.pBitRevTable;
        S->pTwiddle = arm_cfft_sR_f32_len32.pTwiddle;
        rfft_instance->fftLenRFFT = 64U;
        rfft_instance->pTwiddleRFFT = (float32_t *)twiddleCoef_rfft_64;
        status = ARM_MATH_SUCCESS;
        break;
    }
#endif
#if EI_CLASSIFIER_LOAD_FFT_128 == 1
    case 128: {
        arm_cfft_instance_f32 *S = &(rfft_instance->Sint);
        S->fftLen = 64U;
        S->pTwiddle = NULL;
        S->bitRevLength = arm_cfft_sR_f32_len64.bitRevLength;
        S->pBitRevTable = arm_cfft_sR_f32_len64.pBitRevTable;
        S->pTwiddle = arm_cfft_sR_f32_len64.pTwiddle;
        rfft_instance->fftLenRFFT = 128U;
        rfft_instance->pTwiddleRFFT = (float32_t *)twiddleCoef_rfft_128;
        status = ARM_MATH_SUCCESS;
        break;
    }
#endif
#if EI_CLASSIFIER_LOAD_FFT_256 == 1
    case 256: {
        arm_cfft_instance_f32 *S = &(rfft_instance->Sint);
        S->fftLen = 128U;
        S->pTwiddle = NULL;
        S->bitRevLength = arm_cfft_sR_f32_len128.bitRevLength;
        S->pBitRevTable = arm_cfft_sR_f32_len128.pBitRevTable;
        S->pTwiddle = arm_cfft_sR_f32_len128.pTwiddle;
        rfft_instance->fftLenRFFT = 256U;
        rfft_instance->pTwiddleRFFT = (float32_t *)twiddleCoef_rfft_256;
        status = ARM_MATH_SUCCESS;
        break;
    }
#endif
#if EI_CLASSIFIER_LOAD_FFT_512 == 1
    case 512: {
        arm_cfft_instance_f32 *S = &(rfft_instance->Sint);
        S->fftLen = 256U;
        S->pTwiddle = NULL;
        S->bitRevLength = arm_cfft_sR_f32_len256.bitRevLength;
        S->pBitRevTable = arm_cfft_sR_f32_len256.pBitRevTable;
        S->pTwiddle = arm_cfft_sR_f32_len256.pTwiddle;
        rfft_instance->fftLenRFFT = 512U;
        rfft_instance->pTwiddleRFFT = (float32_t *)twiddleCoef_rfft_512;
        status = ARM_MATH_SUCCESS;
        break;
    }
#endif
#if EI_CLASSIFIER_LOAD_FFT_1024 == 1
    case 1024: {
        arm_cfft_instance_f32 *S = &(rfft_instance->Sint);
        S->fftLen = 512U;
        S->pTwiddle = NULL;
        S->bitRevLength = arm_cfft_sR_f32_len512.bitRevLength;
        S->pBitRevTable = arm_cfft_sR_f32_len512.pBitRevTable;
        S->pTwiddle = arm_cfft_sR_f32_len512.pTwiddle;
        rfft_instance->fftLenRFFT = 1024U;
        rfft_instance->pTwiddleRFFT = (float32_t *)twiddleCoef_rfft_1024;
        status = ARM_MATH_SUCCESS;
        break;
    }
#endif
#if EI_CLASSIFIER_LOAD_FFT_2048 == 1
    case 2048: {
        arm_cfft_instance_f32 *S = &(rfft_instance->Sint);
        S->fftLen = 1024U;
        S->pTwiddle = NULL;
        S->bitRevLength = arm_cfft_sR_f32_len1024.bitRevLength;
        S->pBitRevTable = arm_cfft_sR_f32_len1024.pBitRevTable;
        S->pTwiddle = arm_cfft_sR_f32_len1024.pTwiddle;
        rfft_instance->fftLenRFFT = 2048U;
        rfft_instance->pTwiddleRFFT = (float32_t *)twiddleCoef_rfft_2048;
        status = ARM_MATH_SUCCESS;
        break;
    }
#endif
#if EI_CLASSIFIER_LOAD_FFT_4096 == 1
    case 4096: {
        arm_cfft_instance_f32 *S = &(rfft_instance->Sint);
        S->fftLen = 2048U;
        S->pTwiddle = NULL;
        S->bitRevLength = arm_cfft_sR_f32_len2048.bitRevLength;
        S->pBitRevTable = arm_cfft_sR_f32_len2048.pBitRevTable;
        S->pTwiddle = arm_cfft_sR_f32_len2048.pTwiddle;
        rfft_instance->fftLenRFFT = 4096U;
        rfft_instance->pTwiddleRFFT = (float32_t *)twiddleCoef_rfft_4096;
        status = ARM_MATH_SUCCESS;
        break;
    }
#endif
    default:
        return ei::EIDSP_FFT_TABLE_NOT_LOADED;
    }

    return status;
#else
    return arm_rfft_fast_init_f32(rfft_instance, n_fft);
#endif
}

static bool can_do_fft(size_t n_fft)
{
    return n_fft == 32 || n_fft == 64 || n_fft == 128 || n_fft == 256 || n_fft == 512 ||
        n_fft == 1024 || n_fft == 2048 || n_fft == 4096;
}

static int arm_rfft(const float *input, float *output, size_t n_fft)
{
    // hardware acceleration only works for the powers above...
    arm_rfft_fast_instance_f32 rfft_instance;
    int status = cmsis_rfft_init_f32(&rfft_instance, n_fft);
    if (status != ARM_MATH_SUCCESS) {
        return status;
    }

    arm_rfft_fast_f32(&rfft_instance, const_cast<float *>(input), output, 0);
    return 0;
}

static int hw_r2c_fft(const float *input, ei::fft_complex_t *output_as_complex, size_t n_fft)
{
    if(!can_do_fft(n_fft)) { return ei::EIDSP_FFT_SIZE_NOT_SUPPORTED; }

    float *output = (float *)output_as_complex;

    // non zero is fail
    if(arm_rfft(input, output, n_fft)) { return ei::EIDSP_PARAMETER_INVALID; }

    const size_t n_fft_out_features = n_fft / 2 + 1;
    // Take care of the Nyquist bin
    output_as_complex[n_fft_out_features - 1].r = output[1];
    output_as_complex[n_fft_out_features - 1].i = 0.0f;
    output_as_complex[0].i = 0.0f;

    return ei::EIDSP_OK;
}

constexpr int MIN_FFT_SIZE = 32;
constexpr int MAX_FFT_SIZE = 4096;

} // namespace fft

} // namespace ei

#endif //!__EI_ARM_CMSIS_DSP__H__