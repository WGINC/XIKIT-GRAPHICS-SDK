"""lang_files.py DLL [OUT.json]: writes OUT.json (default data/lang_file_tables.json), the four language file-number tables
Scene_GetTableValue (0x1025B560) reads (picked by DmsgText_SelectTableByLanguage, 0x1025B4F0; docs/DATA_FILES.md).
Addresses are the analysed build's (6A995428)."""
import sys, struct, json, pefile
TABLES = {0: 0x1038AB08, 1: 0x1038A548, 2: 0x1038A388, 3: 0x1038A708}   # language number -> table (case table 0x1025B550)
p = pefile.PE(sys.argv[1]); b = p.OPTIONAL_HEADER.ImageBase
if p.FILE_HEADER.TimeDateStamp != 0x6A995428: sys.exit('lang_files: not build 6A995428')
out = {'source': 'image of 6A995428; 112 dwords each', 'tables': {}}
for lang, t in TABLES.items():
    out['tables'][str(lang)] = {'address': '0x%08X' % t, 'files': list(struct.unpack('<112I', p.get_data(t - b, 448)))}
dst = sys.argv[2] if len(sys.argv) > 2 else 'data/lang_file_tables.json'
json.dump(out, open(dst, 'w'), indent=1)
print('wrote', dst)
