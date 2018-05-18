/*
********************************************************************************
*                                Ƕ��ʽ΢ϵͳ
*                               msOS for Mcu51
*
*                          		��оƬ:MCU51
*                           ��������οƼ����޹�˾
*
*                                ����:����ΰ
*                                ����:������
*                                ��ʶ:wangsw
*
*                                QQ:26033613
*                               QQȺ:291235815
*                        �Ա���:http://52edk.taobao.com
*                      ��̳:http://gongkong.eefocus.com/bbs/
*                ����:http://forum.eet-cn.com/BLOG_wangsw317_1268.HTM
********************************************************************************
*�ļ���   : utils.em
*����     : SourceInsightע�ͼ�һЩ����������õ�֧������
*����ʱ�� : 2013.9.2
********************************************************************************
*/


/*******************************************************************************
* ������	: msOSInsertFileHeader
* ����	    : �����ļ�ע��
* �������  : ��
* ���ز���  : ��
*******************************************************************************/
macro msOSInsertFileHeader()
{
    // get aurthor name
    szMyName = getenv(MYNAME)
    if (strlen(szMyName) <= 0)
    {
        szMyName = "Wangsw"
    }

    // get company name
    szCompanyName = getenv(MYCOMPANY)
    if (strlen(szCompanyName) <= 0)
    {
        szCompanyName = szMyName
    }

    // get time
    szTime = GetSysTime(True)
    Day = szTime.Day
    Month = szTime.Month
    Year = szTime.Year
    if (Day < 10)
    {
        szDay = "0@Day@"
    }
    else
    {
        szDay = Day
    }
    if (Month < 10)
    {
        szMonth = "0@Month@"
    }
    else
    {
        szMonth = Month
    }

    // get file name
    hbuf = GetCurrentBuf()
    szpathName = GetBufName(hbuf)
    szfileName = GetFileName(szpathName)
    nlength = StrLen(szfileName)

    // assemble the string
    hbuf = GetCurrentBuf()

    InsBufLine(hbuf, 0,  "/*")
    InsBufLine(hbuf, 1,  "********************************************************************************")
    InsBufLine(hbuf, 2,  "*                                Ƕ��ʽ΢ϵͳ")
    InsBufLine(hbuf, 3,  "*                               msOS for Mcu51")
    InsBufLine(hbuf, 4,  "*")
    InsBufLine(hbuf, 5,  "*                               ��оƬ:MCU51")
    InsBufLine(hbuf, 6,  "*                           ��������οƼ����޹�˾")
    InsBufLine(hbuf, 7,  "*")
    InsBufLine(hbuf, 8,  "*                                ����:����ΰ")
    InsBufLine(hbuf, 9, "*                                ����:������")
    InsBufLine(hbuf, 10, "*                                ��ʶ:Wangsw")
    InsBufLine(hbuf, 11, "*")
    InsBufLine(hbuf, 12, "*                                QQ:26033613")
    InsBufLine(hbuf, 13, "*                               QQȺ:291235815")
    InsBufLine(hbuf, 14, "*                        �Ա���:http://52edk.taobao.com")
    InsBufLine(hbuf, 15, "*                      ��̳:http://gongkong.eefocus.com/bbs/")
    InsBufLine(hbuf, 16, "*                    Google��Դ:https://code.google.com/p/msos/")
    InsBufLine(hbuf, 17, "*                ����:http://forum.eet-cn.com/BLOG_wangsw317_1268.HTM")
    InsBufLine(hbuf, 18, "********************************************************************************")
    InsBufLine(hbuf, 19, "*�ļ���     : @szfileName@")
    InsBufLine(hbuf, 20, "*����       : ")
    InsBufLine(hbuf, 21, "*ԭ��       : ")
    InsBufLine(hbuf, 22, "********************************************************************************")
    InsBufLine(hbuf, 23, "*�汾     ����            ����            ˵��")
    InsBufLine(hbuf, 24, "*V0.1    @szMyName@        @Year@/@szMonth@/@szDay@       ��ʼ�汾")
    InsBufLine(hbuf, 25, "********************************************************************************")
    InsBufLine(hbuf, 26, "*/")

    // put the insertion point
    SetBufIns(hbuf, 27, 0)
}


/*******************************************************************************
* ������	: msOSInsertFunctionHeader
* ����	    : ���뺯��ע��
* �������  : ��
* ���ز���  : ��
*******************************************************************************/
macro msOSInsertFunctionHeader()
{
    // get function name
    hbuf = GetCurrentBuf()
    szFunc = GetCurSymbol()
    ln = GetSymbolLine(szFunc)


    // get aurthor name
    szMyName = getenv(MYNAME)
    if (strlen(szMyName) <= 0)
    {
        szMyName = "Wangsw"
    }

    // get time
    szTime = GetSysTime(True)
    Day = szTime.Day
    Month = szTime.Month
    Year = szTime.Year
    if (Day < 10)
    {
        szDay = "0@Day@"
    }
    else
    {
        szDay = Day
    }
    if (Month < 10)
    {
        szMonth = "0@Month@"
    }
    else
    {
        szMonth = Month
    }

    // assemble the string
    hbuf = GetCurrentBuf()
    InsBufLine(hbuf, ln, "")
    InsBufLine(hbuf, ln+1, "/*******************************************************************************")
    InsBufLine(hbuf, ln+2, "* ������	: @szFunc@")
    InsBufLine(hbuf, ln+3, "* ����	    : ")
    InsBufLine(hbuf, ln+4, "* �������  : ")
    InsBufLine(hbuf, ln+5, "* ���ز���  : ")
    InsBufLine(hbuf, ln+6, "********************************************************************************")
    InsBufLine(hbuf, ln+7, "*�汾     ����            ����            ˵��")
    InsBufLine(hbuf, ln+8, "*V0.1    @szMyName@        @Year@/@szMonth@/@szDay@       ��ʼ�汾")
    InsBufLine(hbuf, ln+9, "*******************************************************************************/")

    // put the insertion point
    SetBufIns(hbuf, ln+10, 0)
}


/*******************************************************************************
* ������	: msOSInsertHFileBanner
* ����	    : ����*.hͷ�ļ����ؼ��������궨��
* �������  : ��
* ���ز���  : ��
*******************************************************************************/
macro msOSInsertHFileBanner()
{
    // get file name
    hbuf = GetCurrentBuf()
    szpathName = GetBufName(hbuf)
    szfileName = GetFileName(szpathName)
    szfileName = toupper(szfileName)

    // create banner
    banner = "__"
    nlength = strlen(szfileName)
	
    i=0
    while (i < nlength)
    {
        if (szfileName[i] == ".")
        {
            banner = cat(banner, "_")
        }
        else
        {
            banner = cat(banner, szfileName[i])
        }

        i = i+1
    }

    //banner = cat(banner, "_")

    // print banner
    hwnd = GetCurrentWnd()
    lnFirst = GetWndSelLnFirst(hwnd)
    lnLast = GetWndSelLnLast(hwnd)
	 
    hbuf = GetCurrentBuf()
    InsBufLine(hbuf, lnFirst, "")
    InsBufLine(hbuf, lnFirst+1, "")
    InsBufLine(hbuf, lnFirst+2, "#ifndef @banner@")
    InsBufLine(hbuf, lnFirst+3, "#define @banner@")
    InsBufLine(hbuf, lnFirst+4, "")
    InsBufLine(hbuf, lnFirst+5, "")
    InsBufLine(hbuf, lnFirst+6, "")
    InsBufLine(hbuf, lnFirst+7, "")
    InsBufLine(hbuf, lnFirst+8, "")
    InsBufLine(hbuf, lnFirst+9, "#endif /*@banner@*/")
    InsBufLine(hbuf, lnFirst+10, "")

    SetBufIns(hbuf, lnFirst+11, 0)
}

/*==================================================================
* Function	: GetFileName
* Description	: get file name from path
*			  
* Input Para	: pathName	: path string
			  
* Output Para	: None
			  
* Return Value: name		: file name
==================================================================*/
macro GetFileName(pathName)
{
    nlength = strlen(pathName)
    i = nlength - 1
    name = ""
    while (i + 1)
    {
        ch = pathName[i]
        if ("\\" == "@ch@")
            break
        i = i - 1
    }
    i = i + 1
    while (i < nlength)
    {
        name = cat(name, pathName[i])
        i = i + 1
    }

    return name
}
