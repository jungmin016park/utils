#include "lib/xa_type_def.h"
typedef void WindNRObj;
typedef void CNGVariables;
typedef void NEstVariables;
typedef void LG_TSE_FRWK_T;
typedef void NRVariables;
typedef void VADVariables;
typedef void LG_TSE_PARAMS_T;
typedef void data_que;
typedef void LG_PCM_T;
typedef int LG_TSE_RETURN_T;
typedef void AEC_OBJ_T;
typedef void AEC_Params_T;
typedef void WindNRParams;
typedef void RCV_Params_T;
typedef void RCV_Object_T;


//void InitWindNRObj(WindNRObj * WNRObj, const short SkipBins, const unsigned int SamplingRate)
void InitWindNRObj(WindNRObj * WNRObj, const short SkipBins, const unsigned int SamplingRate )
{
    void (*fp_InitWindNRObj)(WindNRObj * , const short , const unsigned int SamplingRate ) = (void (*)(WindNRObj * , const short , const unsigned int SamplingRate ))0x48fd3288;
    return fp_InitWindNRObj(WNRObj, SkipBins, SamplingRate);
}
//void ComfNoiseGenProc(CNGVariables * CNGVar, const float * AECOutPow)
void ComfNoiseGenProc(CNGVariables * CNGVar, const float * AECOutPow )
{
    void (*fp_ComfNoiseGenProc)(CNGVariables * , const float * AECOutPow ) = (void (*)(CNGVariables * , const float * AECOutPow ))0x48fcead4;
    return fp_ComfNoiseGenProc(CNGVar, AECOutPow);
}
//void SetNoiseEstParamsToDefault(NEstVariables * NEVar)
void SetNoiseEstParamsToDefault(NEstVariables * NEVar)
{
    void (*fp_SetNoiseEstParamsToDefault)(NEstVariables * )  = (void (*)(NEstVariables * ) )0x48fd34c8;
    return fp_SetNoiseEstParamsToDefault(NEVar);
}
//const float * Get_DROM_Table_Matrix_Array_Square1_1024()
const float * Get_DROM_Table_Matrix_Array_Square1_1024()
{
    const float * (*fp_Get_DROM_Table_Matrix_Array_Square1_1024)()  = (const float * (*)() )0x48fcf030;
    return fp_Get_DROM_Table_Matrix_Array_Square1_1024();
}
//void InitWindNoiseEst(NEstVariables * NEVar, const float * InSpecPow)
void InitWindNoiseEst(NEstVariables * NEVar, const float * InSpecPow )
{
    void (*fp_InitWindNoiseEst)(NEstVariables * , const float * InSpecPow ) = (void (*)(NEstVariables * , const float * InSpecPow ))0x48fd3854;
    return fp_InitWindNoiseEst(NEVar, InSpecPow);
}
//LG_TSE_RETURN_T _TSE_InitCGM(LG_TSE_FRWK_T * prepro)
LG_TSE_RETURN_T _TSE_InitCGM(LG_TSE_FRWK_T * prepro)
{
    LG_TSE_RETURN_T (*fp__TSE_InitCGM)(LG_TSE_FRWK_T * )  = (LG_TSE_RETURN_T (*)(LG_TSE_FRWK_T * ) )0x48fcf4e0;
    return fp__TSE_InitCGM(prepro);
}
//void CalLSAGainAndSPP(NRVariables * NRVar)
void CalLSAGainAndSPP(NRVariables * NRVar)
{
    void (*fp_CalLSAGainAndSPP)(NRVariables * )  = (void (*)(NRVariables * ) )0x48fce0ec;
    return fp_CalLSAGainAndSPP(NRVar);
}
//LG_TSE_RETURN_T _TSE_CheckHandle(LG_TSE_FRWK_T * prepro)
LG_TSE_RETURN_T _TSE_CheckHandle(LG_TSE_FRWK_T * prepro)
{
    LG_TSE_RETURN_T (*fp__TSE_CheckHandle)(LG_TSE_FRWK_T * )  = (LG_TSE_RETURN_T (*)(LG_TSE_FRWK_T * ) )0x48fcf790;
    return fp__TSE_CheckHandle(prepro);
}
//LG_TSE_RETURN_T _TSE_DeInitFrwk(LG_TSE_FRWK_T * prepro)
LG_TSE_RETURN_T _TSE_DeInitFrwk(LG_TSE_FRWK_T * prepro)
{
    LG_TSE_RETURN_T (*fp__TSE_DeInitFrwk)(LG_TSE_FRWK_T * )  = (LG_TSE_RETURN_T (*)(LG_TSE_FRWK_T * ) )0x48fcf1ec;
    return fp__TSE_DeInitFrwk(prepro);
}
//void CreateComfNoiseGenObj(CNGVariables * CNGVar, const short NumBin, const unsigned int SamplingRate)
void CreateComfNoiseGenObj(CNGVariables * CNGVar, const short NumBin, const unsigned int SamplingRate )
{
    void (*fp_CreateComfNoiseGenObj)(CNGVariables * , const short , const unsigned int SamplingRate ) = (void (*)(CNGVariables * , const short , const unsigned int SamplingRate ))0x48fcea94;
    return fp_CreateComfNoiseGenObj(CNGVar, NumBin, SamplingRate);
}
//XA_ERRORCODE xa_msbc_dec(xa_codec_handle_t p_xa_module_obj,WORD32 i_cmd,WORD32 i_idx,pVOID pv_value)
XA_ERRORCODE xa_msbc_dec(xa_codec_handle_t p_xa_module_obj,WORD32 i_cmd,WORD32 i_idx,pVOID pv_value)
{
    XA_ERRORCODE (*fp_xa_msbc_dec)(xa_codec_handle_t ,WORD32 ,WORD32 ,pVOID ) = (XA_ERRORCODE (*)(xa_codec_handle_t ,WORD32 ,WORD32 ,pVOID ))0x48fc1f0c;
    return fp_xa_msbc_dec(p_xa_module_obj, i_cmd, i_idx, pv_value);
}
//void InitComfNoiseGen(CNGVariables * CNGVar, const float * AECOutPow)
void InitComfNoiseGen(CNGVariables * CNGVar, const float * AECOutPow )
{
    void (*fp_InitComfNoiseGen)(CNGVariables * , const float * AECOutPow ) = (void (*)(CNGVariables * , const float * AECOutPow ))0x48fcefe8;
    return fp_InitComfNoiseGen(CNGVar, AECOutPow);
}
//void CalWNRGainFloor(NRVariables * NRVar, const float * BNPSD)
void CalWNRGainFloor(NRVariables * NRVar, const float * BNPSD )
{
    void (*fp_CalWNRGainFloor)(NRVariables * , const float * BNPSD ) = (void (*)(NRVariables * , const float * BNPSD ))0x48fcdb9c;
    return fp_CalWNRGainFloor(NRVar, BNPSD);
}
//void CreateSingleChVADObj(VADVariables * VADVar, const short NFFT, const short NumBin, const unsigned int SamplingRate)
void CreateSingleChVADObj(VADVariables * VADVar, const short NFFT, const short NumBin, const unsigned int SamplingRate )
{
    void (*fp_CreateSingleChVADObj)(VADVariables * , const short , const short , const unsigned int SamplingRate ) = (void (*)(VADVariables * , const short , const short , const unsigned int SamplingRate ))0x48fd011c;
    return fp_CreateSingleChVADObj(VADVar, NFFT, NumBin, SamplingRate);
}
//void WindNoiseEstProc(NEstVariables * NEVar, const float * InSpecPow, const float * AECOutSpecPow, const float * VADRes)
void WindNoiseEstProc(NEstVariables * NEVar, const float * InSpecPow, const float * AECOutSpecPow, const float * VADRes )
{
    void (*fp_WindNoiseEstProc)(NEstVariables * , const float * , const float * , const float * VADRes ) = (void (*)(NEstVariables * , const float * , const float * , const float * VADRes ))0x48fd369c;
    return fp_WindNoiseEstProc(NEVar, InSpecPow, AECOutSpecPow, VADRes);
}
//LG_TSE_RETURN_T TSE_CheckValidHandle(LG_TSE_FRWK_T * prepro)
LG_TSE_RETURN_T TSE_CheckValidHandle(LG_TSE_FRWK_T * prepro)
{
    LG_TSE_RETURN_T (*fp_TSE_CheckValidHandle)(LG_TSE_FRWK_T * )  = (LG_TSE_RETURN_T (*)(LG_TSE_FRWK_T * ) )0x48fcf7a0;
    return fp_TSE_CheckValidHandle(prepro);
}
//XA_ERRORCODE xa_aac_dec(xa_codec_handle_t p_xa_module_obj,WORD32 i_cmd,WORD32 i_idx,pVOID pv_value)
XA_ERRORCODE xa_aac_dec(xa_codec_handle_t p_xa_module_obj,WORD32 i_cmd,WORD32 i_idx,pVOID pv_value)
{
    XA_ERRORCODE (*fp_xa_aac_dec)(xa_codec_handle_t ,WORD32 ,WORD32 ,pVOID ) = (XA_ERRORCODE (*)(xa_codec_handle_t ,WORD32 ,WORD32 ,pVOID ))0x48fcbd1c;
    return fp_xa_aac_dec(p_xa_module_obj, i_cmd, i_idx, pv_value);
}
//void SetupComfNoiseGen(CNGVariables * CNGVar, const float * AECOutPow, const short SkipBins, const float BinRes)
void SetupComfNoiseGen(CNGVariables * CNGVar, const float * AECOutPow, const short SkipBins, const float BinRes )
{
    void (*fp_SetupComfNoiseGen)(CNGVariables * , const float * , const short , const float BinRes ) = (void (*)(CNGVariables * , const float * , const short , const float BinRes ))0x48fcecdc;
    return fp_SetupComfNoiseGen(CNGVar, AECOutPow, SkipBins, BinRes);
}
//void AEC_FilterUpdateOnly(float * Mic, float * Ref, float * Wt, float * Err, float * Pwr, float mu, float reg, short N, short st, short ed)
void AEC_FilterUpdateOnly(float * Mic, float * Ref, float * Wt, float * Err, float * Pwr, float mu, float reg, short N, short st, short ed )
{
    void (*fp_AEC_FilterUpdateOnly)(float * , float * , float * , float * , float * , float , float , short , short , short ed ) = (void (*)(float * , float * , float * , float * , float * , float , float , short , short , short ed ))0x48fcd4bc;
    return fp_AEC_FilterUpdateOnly(Mic, Ref, Wt, Err, Pwr, mu, reg, N, st, ed);
}
//void AEC_Init(unsigned int SamplingRate, AEC_OBJ_T * h, AEC_Params_T * Param)
void AEC_Init(unsigned int SamplingRate, AEC_OBJ_T * h, AEC_Params_T * Param )
{
    void (*fp_AEC_Init)(unsigned int , AEC_OBJ_T * , AEC_Params_T * Param ) = (void (*)(unsigned int , AEC_OBJ_T * , AEC_Params_T * Param ))0x48fcc920;
    return fp_AEC_Init(SamplingRate, h, Param);
}
//LG_TSE_RETURN_T _TSE_CheckParams(LG_TSE_PARAMS_T * pParam)
LG_TSE_RETURN_T _TSE_CheckParams(LG_TSE_PARAMS_T * pParam)
{
    LG_TSE_RETURN_T (*fp__TSE_CheckParams)(LG_TSE_PARAMS_T * )  = (LG_TSE_RETURN_T (*)(LG_TSE_PARAMS_T * ) )0x48fcf70c;
    return fp__TSE_CheckParams(pParam);
}
//void CreateNoiseEstObj(NEstVariables * NEVar, const short NFFT, const short NumBin, const unsigned int SamplingRate)
void CreateNoiseEstObj(NEstVariables * NEVar, const short NFFT, const short NumBin, const unsigned int SamplingRate )
{
    void (*fp_CreateNoiseEstObj)(NEstVariables * , const short , const short , const unsigned int SamplingRate ) = (void (*)(NEstVariables * , const short , const short , const unsigned int SamplingRate ))0x48fd3544;
    return fp_CreateNoiseEstObj(NEVar, NFFT, NumBin, SamplingRate);
}
//LG_TSE_RETURN_T _TSE_ConnectQueue(LG_TSE_FRWK_T * prepro, LG_TSE_PARAMS_T * pParam)
LG_TSE_RETURN_T _TSE_ConnectQueue(LG_TSE_FRWK_T * prepro, LG_TSE_PARAMS_T * pParam )
{
    LG_TSE_RETURN_T (*fp__TSE_ConnectQueue)(LG_TSE_FRWK_T * , LG_TSE_PARAMS_T * pParam ) = (LG_TSE_RETURN_T (*)(LG_TSE_FRWK_T * , LG_TSE_PARAMS_T * pParam ))0x48fcf0f0;
    return fp__TSE_ConnectQueue(prepro, pParam);
}
//int convertBufferToParam(char * pSourceBuffer, int bufferSize, LG_TSE_PARAMS_T * pParam)
int convertBufferToParam(char * pSourceBuffer, int bufferSize, LG_TSE_PARAMS_T * pParam )
{
    int (*fp_convertBufferToParam)(char * , int , LG_TSE_PARAMS_T * pParam ) = (int (*)(char * , int , LG_TSE_PARAMS_T * pParam ))0x48fcf0c0;
    return fp_convertBufferToParam(pSourceBuffer, bufferSize, pParam);
}
//LG_TSE_RETURN_T _TSE_DoCGM(LG_TSE_FRWK_T * prepro, LG_PCM_T * in_out, unsigned int size, float gain)
LG_TSE_RETURN_T _TSE_DoCGM(LG_TSE_FRWK_T * prepro, LG_PCM_T * in_out, unsigned int size, float gain )
{
    LG_TSE_RETURN_T (*fp__TSE_DoCGM)(LG_TSE_FRWK_T * , LG_PCM_T * , unsigned int , float gain ) = (LG_TSE_RETURN_T (*)(LG_TSE_FRWK_T * , LG_PCM_T * , unsigned int , float gain ))0x48fcfb38;
    return fp__TSE_DoCGM(prepro, in_out, size, gain);
}
//void CalAPrioriSAP(NRVariables * NRVar)
void CalAPrioriSAP(NRVariables * NRVar)
{
    void (*fp_CalAPrioriSAP)(NRVariables * )  = (void (*)(NRVariables * ) )0x48fcdce8;
    return fp_CalAPrioriSAP(NRVar);
}
//void InitSpectralNRGainObjLSA(NRVariables * NRVar, const short SkipBins)
void InitSpectralNRGainObjLSA(NRVariables * NRVar, const short SkipBins )
{
    void (*fp_InitSpectralNRGainObjLSA)(NRVariables * , const short SkipBins ) = (void (*)(NRVariables * , const short SkipBins ))0x48fcda64;
    return fp_InitSpectralNRGainObjLSA(NRVar, SkipBins);
}
//void nomnalized_float_to_short(float * in, LG_PCM_T * out, unsigned int size)
void nomnalized_float_to_short(float * in, LG_PCM_T * out, unsigned int size )
{
    void (*fp_nomnalized_float_to_short)(float * , LG_PCM_T * , unsigned int size ) = (void (*)(float * , LG_PCM_T * , unsigned int size ))0x48fcfb8c;
    return fp_nomnalized_float_to_short(in, out, size);
}
//const float * Get_DROM_Table_mic_gain()
const float * Get_DROM_Table_mic_gain()
{
    const float * (*fp_Get_DROM_Table_mic_gain)()  = (const float * (*)() )0x48fcf048;
    return fp_Get_DROM_Table_mic_gain();
}
//const float * Get_DROM_Table_vol_table()
const float * Get_DROM_Table_vol_table()
{
    const float * (*fp_Get_DROM_Table_vol_table)()  = (const float * (*)() )0x48fcf050;
    return fp_Get_DROM_Table_vol_table();
}
//void CalOMLSAGain(NRVariables * NRVar)
void CalOMLSAGain(NRVariables * NRVar)
{
    void (*fp_CalOMLSAGain)(NRVariables * )  = (void (*)(NRVariables * ) )0x48fce594;
    return fp_CalOMLSAGain(NRVar);
}
//void SetCNGParamsToDefault(CNGVariables * CNGVar)
void SetCNGParamsToDefault(CNGVariables * CNGVar)
{
    void (*fp_SetCNGParamsToDefault)(CNGVariables * )  = (void (*)(CNGVariables * ) )0x48fcea78;
    return fp_SetCNGParamsToDefault(CNGVar);
}
//void rdft(int n, int isgn, float * a, int * ip, float * w)
void rdft(int n, int isgn, float * a, int * ip, float * w )
{
    void (*fp_rdft)(int , int , float * , int * , float * w ) = (void (*)(int , int , float * , int * , float * w ))0x48fd4a20;
    return fp_rdft(n, isgn, a, ip, w);
}
//const short * Get_DROM_Table_CliqueStPt()
const short * Get_DROM_Table_CliqueStPt()
{
    const short * (*fp_Get_DROM_Table_CliqueStPt)()  = (const short * (*)() )0x48fcf058;
    return fp_Get_DROM_Table_CliqueStPt();
}
//LG_TSE_RETURN_T _TSE_InitAEC(LG_TSE_FRWK_T * prepro)
LG_TSE_RETURN_T _TSE_InitAEC(LG_TSE_FRWK_T * prepro)
{
    LG_TSE_RETURN_T (*fp__TSE_InitAEC)(LG_TSE_FRWK_T * )  = (LG_TSE_RETURN_T (*)(LG_TSE_FRWK_T * ) )0x48fcf3b4;
    return fp__TSE_InitAEC(prepro);
}
//const short * Get_DROM_Table_CliqueEdPt()
const short * Get_DROM_Table_CliqueEdPt()
{
    const short * (*fp_Get_DROM_Table_CliqueEdPt)()  = (const short * (*)() )0x48fcf060;
    return fp_Get_DROM_Table_CliqueEdPt();
}
//void short_to_nomnalized_float(LG_PCM_T * in_out, unsigned int size)
void short_to_nomnalized_float(LG_PCM_T * in_out, unsigned int size )
{
    void (*fp_short_to_nomnalized_float)(LG_PCM_T * , unsigned int size ) = (void (*)(LG_PCM_T * , unsigned int size ))0x48fcfb64;
    return fp_short_to_nomnalized_float(in_out, size);
}
//const float * Get_DROM_Table_Matrix_Array_Square1p35_512()
const float * Get_DROM_Table_Matrix_Array_Square1p35_512()
{
    const float * (*fp_Get_DROM_Table_Matrix_Array_Square1p35_512)()  = (const float * (*)() )0x48fcf028;
    return fp_Get_DROM_Table_Matrix_Array_Square1p35_512();
}
//int data_que_pop(data_que * que, char * data, unsigned int nque, unsigned int isPeek)
int data_que_pop(data_que * que, char * data, unsigned int nque, unsigned int isPeek )
{
    int (*fp_data_que_pop)(data_que * , char * , unsigned int , unsigned int isPeek ) = (int (*)(data_que * , char * , unsigned int , unsigned int isPeek ))0x48fd4964;
    return fp_data_que_pop(que, data, nque, isPeek);
}
//XA_ERRORCODE xa_msbc_enc(xa_codec_handle_t p_xa_module_obj,WORD32 i_cmd,WORD32 i_idx,pVOID pv_value)
XA_ERRORCODE xa_msbc_enc(xa_codec_handle_t p_xa_module_obj,WORD32 i_cmd,WORD32 i_idx,pVOID pv_value)
{
    XA_ERRORCODE (*fp_xa_msbc_enc)(xa_codec_handle_t ,WORD32 ,WORD32 ,pVOID ) = (XA_ERRORCODE (*)(xa_codec_handle_t ,WORD32 ,WORD32 ,pVOID ))0x48fc3234;
    return fp_xa_msbc_enc(p_xa_module_obj, i_cmd, i_idx, pv_value);
}
//void AEC_CalErrorWithPBS(float * Mic, float * Ref, float * Wt, float * Err, short N, float OverThr, float OverWeight)
void AEC_CalErrorWithPBS(float * Mic, float * Ref, float * Wt, float * Err, short N, float OverThr, float OverWeight )
{
    void (*fp_AEC_CalErrorWithPBS)(float * , float * , float * , float * , short , float , float OverWeight ) = (void (*)(float * , float * , float * , float * , short , float , float OverWeight ))0x48fcd58c;
    return fp_AEC_CalErrorWithPBS(Mic, Ref, Wt, Err, N, OverThr, OverWeight);
}
//const float * Get_DROM_Table_FrameWindow_8k()
const float * Get_DROM_Table_FrameWindow_8k()
{
    const float * (*fp_Get_DROM_Table_FrameWindow_8k)()  = (const float * (*)() )0x48fcf040;
    return fp_Get_DROM_Table_FrameWindow_8k();
}
//LG_TSE_RETURN_T _TSE_InitBF(LG_TSE_FRWK_T * prepro)
LG_TSE_RETURN_T _TSE_InitBF(LG_TSE_FRWK_T * prepro)
{
    LG_TSE_RETURN_T (*fp__TSE_InitBF)(LG_TSE_FRWK_T * )  = (LG_TSE_RETURN_T (*)(LG_TSE_FRWK_T * ) )0x48fcf46c;
    return fp__TSE_InitBF(prepro);
}
//LG_TSE_RETURN_T TSE_ParamToPrepro(LG_TSE_FRWK_T * prepro, LG_TSE_PARAMS_T * pParam)
LG_TSE_RETURN_T TSE_ParamToPrepro(LG_TSE_FRWK_T * prepro, LG_TSE_PARAMS_T * pParam )
{
    LG_TSE_RETURN_T (*fp_TSE_ParamToPrepro)(LG_TSE_FRWK_T * , LG_TSE_PARAMS_T * pParam ) = (LG_TSE_RETURN_T (*)(LG_TSE_FRWK_T * , LG_TSE_PARAMS_T * pParam ))0x48fcfac8;
    return fp_TSE_ParamToPrepro(prepro, pParam);
}
//void AEC_CalError(float * Mic, float * Ref, float * Wt, float * Err, short N)
void AEC_CalError(float * Mic, float * Ref, float * Wt, float * Err, short N )
{
    void (*fp_AEC_CalError)(float * , float * , float * , float * , short N ) = (void (*)(float * , float * , float * , float * , short N ))0x48fcd544;
    return fp_AEC_CalError(Mic, Ref, Wt, Err, N);
}
//int data_que_push(data_que * que, char * data, unsigned int nque)
int data_que_push(data_que * que, char * data, unsigned int nque )
{
    int (*fp_data_que_push)(data_que * , char * , unsigned int nque ) = (int (*)(data_que * , char * , unsigned int nque ))0x48fd488c;
    return fp_data_que_push(que, data, nque);
}
//void GetWindNRParamsTune(WindNRObj * WNRObj, const WindNRParams * WNRParams)
void GetWindNRParamsTune(WindNRObj * WNRObj, const WindNRParams * WNRParams )
{
    void (*fp_GetWindNRParamsTune)(WindNRObj * , const WindNRParams * WNRParams ) = (void (*)(WindNRObj * , const WindNRParams * WNRParams ))0x48fd1618;
    return fp_GetWindNRParamsTune(WNRObj, WNRParams);
}
//const float * Get_DROM_Table_VAD_VarSmthTbl()
const float * Get_DROM_Table_VAD_VarSmthTbl()
{
    const float * (*fp_Get_DROM_Table_VAD_VarSmthTbl)()  = (const float * (*)() )0x48fcf078;
    return fp_Get_DROM_Table_VAD_VarSmthTbl();
}
//LG_TSE_RETURN_T _TSE_InitRCV(LG_TSE_FRWK_T * prepro)
LG_TSE_RETURN_T _TSE_InitRCV(LG_TSE_FRWK_T * prepro)
{
    LG_TSE_RETURN_T (*fp__TSE_InitRCV)(LG_TSE_FRWK_T * )  = (LG_TSE_RETURN_T (*)(LG_TSE_FRWK_T * ) )0x48fcf344;
    return fp__TSE_InitRCV(prepro);
}
//const float * Get_DROM_Table_FrameWindow_16k()
const float * Get_DROM_Table_FrameWindow_16k()
{
    const float * (*fp_Get_DROM_Table_FrameWindow_16k)()  = (const float * (*)() )0x48fcf038;
    return fp_Get_DROM_Table_FrameWindow_16k();
}
//void SetupWindNoiseEst(NEstVariables * NEVar, const float * InSpecPow)
void SetupWindNoiseEst(NEstVariables * NEVar, const float * InSpecPow )
{
    void (*fp_SetupWindNoiseEst)(NEstVariables * , const float * InSpecPow ) = (void (*)(NEstVariables * , const float * InSpecPow ))0x48fd373c;
    return fp_SetupWindNoiseEst(NEVar, InSpecPow);
}
//void InitSpectralNRGainObj(NRVariables * NRVar, const short SkipBins)
void InitSpectralNRGainObj(NRVariables * NRVar, const short SkipBins )
{
    void (*fp_InitSpectralNRGainObj)(NRVariables * , const short SkipBins ) = (void (*)(NRVariables * , const short SkipBins ))0x48fcd788;
    return fp_InitSpectralNRGainObj(NRVar, SkipBins);
}
//void InitSpectralNRGain(NRVariables * NRVar, const float * InSpecPow)
void InitSpectralNRGain(NRVariables * NRVar, const float * InSpecPow )
{
    void (*fp_InitSpectralNRGain)(NRVariables * , const float * InSpecPow ) = (void (*)(NRVariables * , const float * InSpecPow ))0x48fcd738;
    return fp_InitSpectralNRGain(NRVar, InSpecPow);
}
//void RCV_Init(int sample_rate, int size, RCV_Params_T * params, RCV_Object_T * object)
void RCV_Init(int sample_rate, int size, RCV_Params_T * params, RCV_Object_T * object )
{
    void (*fp_RCV_Init)(int , int , RCV_Params_T * , RCV_Object_T * object ) = (void (*)(int , int , RCV_Params_T * , RCV_Object_T * object ))0x48fcfba8;
    return fp_RCV_Init(sample_rate, size, params, object);
}
//LG_TSE_RETURN_T TSE_PreproToParam(LG_TSE_FRWK_T * prepro, LG_TSE_PARAMS_T * pParam)
LG_TSE_RETURN_T TSE_PreproToParam(LG_TSE_FRWK_T * prepro, LG_TSE_PARAMS_T * pParam )
{
    LG_TSE_RETURN_T (*fp_TSE_PreproToParam)(LG_TSE_FRWK_T * , LG_TSE_PARAMS_T * pParam ) = (LG_TSE_RETURN_T (*)(LG_TSE_FRWK_T * , LG_TSE_PARAMS_T * pParam ))0x48fcfa50;
    return fp_TSE_PreproToParam(prepro, pParam);
}
//void AEC_FilterUpdate(float * Mic, float * Ref, float * Wt, float * Pwr, float mu, float reg, short N, short st, short ed)
void AEC_FilterUpdate(float * Mic, float * Ref, float * Wt, float * Pwr, float mu, float reg, short N, short st, short ed )
{
    void (*fp_AEC_FilterUpdate)(float * , float * , float * , float * , float , float , short , short , short ed ) = (void (*)(float * , float * , float * , float * , float , float , short , short , short ed ))0x48fcd3c0;
    return fp_AEC_FilterUpdate(Mic, Ref, Wt, Pwr, mu, reg, N, st, ed);
}
//void CalPSDwithEQ(LG_PCM_T * in, float * out, float * pEQNode, float * pEQ, short Len, short sLen, short mLen)
void CalPSDwithEQ(LG_PCM_T * in, float * out, float * pEQNode, float * pEQ, short Len, short sLen, short mLen )
{
    void (*fp_CalPSDwithEQ)(LG_PCM_T * , float * , float * , float * , short , short , short mLen ) = (void (*)(LG_PCM_T * , float * , float * , float * , short , short , short mLen ))0x48fd038c;
    return fp_CalPSDwithEQ(in, out, pEQNode, pEQ, Len, sLen, mLen);
}
//const float * Get_DROM_Table_win_16k()
const float * Get_DROM_Table_win_16k()
{
    const float * (*fp_Get_DROM_Table_win_16k)()  = (const float * (*)() )0x48fcf068;
    return fp_Get_DROM_Table_win_16k();
}
//XA_ERRORCODE xa_sbc_dec(xa_codec_handle_t p_xa_module_obj,WORD32 i_cmd,WORD32 i_idx,pVOID pv_value)
XA_ERRORCODE xa_sbc_dec(xa_codec_handle_t p_xa_module_obj,WORD32 i_cmd,WORD32 i_idx,pVOID pv_value)
{
    XA_ERRORCODE (*fp_xa_sbc_dec)(xa_codec_handle_t ,WORD32 ,WORD32 ,pVOID ) = (XA_ERRORCODE (*)(xa_codec_handle_t ,WORD32 ,WORD32 ,pVOID ))0x48fc1128;
    return fp_xa_sbc_dec(p_xa_module_obj, i_cmd, i_idx, pv_value);
}
//LG_TSE_RETURN_T _TSE_CreateQueue(LG_TSE_FRWK_T * prepro, LG_TSE_PARAMS_T * pParam)
LG_TSE_RETURN_T _TSE_CreateQueue(LG_TSE_FRWK_T * prepro, LG_TSE_PARAMS_T * pParam )
{
    LG_TSE_RETURN_T (*fp__TSE_CreateQueue)(LG_TSE_FRWK_T * , LG_TSE_PARAMS_T * pParam ) = (LG_TSE_RETURN_T (*)(LG_TSE_FRWK_T * , LG_TSE_PARAMS_T * pParam ))0x48fcf14c;
    return fp__TSE_CreateQueue(prepro, pParam);
}
//void SetWindNRParamsToDefault(WindNRObj * WNRObj)
void SetWindNRParamsToDefault(WindNRObj * WNRObj)
{
    void (*fp_SetWindNRParamsToDefault)(WindNRObj * )  = (void (*)(WindNRObj * ) )0x48fd321c;
    return fp_SetWindNRParamsToDefault(WNRObj);
}
//void CalLSAGain(NRVariables * NRVar)
void CalLSAGain(NRVariables * NRVar)
{
    void (*fp_CalLSAGain)(NRVariables * ) = (void (*)(NRVariables * ))0x48fce358;
    return fp_CalLSAGain(NRVar);
}
//void SetVADParamsToDefault(VADVariables * VADVar)
void SetVADParamsToDefault(VADVariables * VADVar)
{
    void (*fp_SetVADParamsToDefault)(VADVariables * )  = (void (*)(VADVariables * ) )0x48fd0098;
    return fp_SetVADParamsToDefault(VADVar);
}
//void CalAPrioriSNR(NRVariables * NRVar, const float * InSpecPow, const float * NoisePSD, const float * NRGain)
void CalAPrioriSNR(NRVariables * NRVar, const float * InSpecPow, const float * NoisePSD, const float * NRGain )
{
    void (*fp_CalAPrioriSNR)(NRVariables * , const float * , const float * , const float * NRGain ) = (void (*)(NRVariables * , const float * , const float * , const float * NRGain ))0x48fcdc4c;
    return fp_CalAPrioriSNR(NRVar, InSpecPow, NoisePSD, NRGain);
}
//void GetWindNRParams(WindNRObj * WNRObj, const WindNRParams * WNRParams)
void GetWindNRParams(WindNRObj * WNRObj, const WindNRParams * WNRParams )
{
    void (*fp_GetWindNRParams)(WindNRObj * , const WindNRParams * WNRParams ) = (void (*)(WindNRObj * , const WindNRParams * WNRParams ))0x48fd04a4;
    return fp_GetWindNRParams(WNRObj, WNRParams);
}
//const float * Get_DROM_Table_win_8k()
const float * Get_DROM_Table_win_8k()
{
    const float * (*fp_Get_DROM_Table_win_8k)()  = (const float * (*)() )0x48fcf070;
    return fp_Get_DROM_Table_win_8k();
}

const void *Get_Keytone_Table(int hz)
{
  void *addr;

  switch(hz) {
  case 400 :
    addr = (void *)0x48f60000;
    break;
  case 500 :
    addr = (void *)0x48f601e0;
    break;
  case 600 :
    addr = (void *)0x48f60360;
    break;
  case 800 :
    addr = (void *)0x48f604a0;
    break;
  case 1000 :
    addr = (void *)0x48f60590;
    break;
  case 1200 :
    addr = (void *)0x48f60650;
    break;
  default :
    break;
  }
  return addr;
}


typedef union
           {          /* pun float types as integer array */
           unsigned short _Word[8];
           float _Float;
           double _Double;
           long double _Long_double;
           } _Dconst;


extern _Dconst _FDenorm, _FInf, _FNan, _FSnan, _FEps, _FRteps;
extern float _FXbig, _FZero;

