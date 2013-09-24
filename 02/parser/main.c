#include <stdlib.h>

#include <antlr3defs.h>

#include "ParserLexer.h"
#include "ParserParser.h"
#include "ASTParser.h"

int main(int argc, char **argv)
{
	pANTLR3_INPUT_STREAM input;
	pANTLR3_COMMON_TOKEN_STREAM tstream;
	pANTLR3_COMMON_TREE_NODE_STREAM tnstream;
	ParserParser_translationUnit_return parseTree;
	pParserLexer lxr;
	pParserParser psr;
	pASTParser ASTp;
	int ret = 1;

	if (argc < 2)
		goto err;

	ret++;

	input = antlr3FileStreamNew((pANTLR3_UINT8)argv[1], ANTLR3_ENC_8BIT);
	if (!input)
		goto err;
	ret++;
	lxr = ParserLexerNew(input);
	if (!lxr)
		goto err_input;
	ret++;
	tstream = antlr3CommonTokenStreamSourceNew(ANTLR3_SIZE_HINT, TOKENSOURCE(lxr));
	if (!tstream)
		goto err_lxr;
	ret++;
	psr = ParserParserNew(tstream);
	if (!psr)
		goto err_tstream;

	parseTree = psr->translationUnit(psr);

	puts((char *)parseTree.tree->toStringTree(parseTree.tree)->chars);

	ret++;
	tnstream = antlr3CommonTreeNodeStreamNewTree(parseTree.tree,
			ANTLR3_SIZE_HINT);
	if (!tnstream)
		goto err_psr;

	ret++;
	ASTp = ASTParserNew(tnstream);
	if (!ASTp)
		goto err_tnstream;

	ASTp->translationUnit(ASTp);

	ret = 0;

	ASTp->free(ASTp);
err_tnstream:
	tnstream->free(tnstream);
err_psr:
	psr->free(psr);
err_tstream:
	tstream->free(tstream);
err_lxr:
	lxr->free(lxr);
err_input:
	input->close(input);
err:
	return ret;
}
